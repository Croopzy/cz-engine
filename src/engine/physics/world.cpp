#include <iostream>
#include "World.hpp"

// Constructor
World::World(const std::string& inName, const Vector& inGravity) noexcept // Uses Intitialiser List To Set World Parameters
    : name(inName),
    gravity(inGravity)
{}

void World::printInfo(const bool listParticles) noexcept {
    std::cout << "\nWorld: " << World::name << " {"
    << "\n- Gravity = " << World::gravity.y << "ms^-2";
    if (listParticles) {
        std::cout << "\n- Particles: ";
        for (Particle& body : particles) {
            std::cout << body.name << " (" << "Mass = " << body.mass << "kg, " << "Position = " << body.position << " ";
        }
    }
    std::cout << "}\n";
}

// Apply Spring Force
void World::applySpringForce(const Spring& spring) {
    // Refer To Both Particles By Index
    Particle& bodyA = particles[spring.particleA];
    Particle& bodyB = particles[spring.particleB];
    // Vector From A -> B
    Vector delta = bodyB.position - bodyA.position;
    float currentLength = magnitude(delta);
    if (currentLength == 0.0f) return; // Avoids Division by Zero
    Vector direction = normalise(delta); // normalise(delta) == delta / currentLength
    // (+ve extension = stretched), (-ve extension = compressed)
    float extension = currentLength - spring.naturalLength;
    // Hooke's Law: F = -kxd
    Vector stiffnessForce = -spring.stiffness * extension * direction;
    // Relative Velocity
    Vector relativeVelocity = bodyB.velocity - bodyA.velocity; // Velocity of B Relative to Velocity of A
    // Component of Relative Velocity Along Spring Axis (Signed Scalar)
    float vParallel = dot(relativeVelocity, direction); // Changes Extension Since Direction Parallel To Plane
    // Damping Force: F = -kpd
    Vector dampingForce = -spring.damping * vParallel * direction;
    // Total Spring Force Vector (A -> B)
    Vector springForce = stiffnessForce + dampingForce;
    // Apply Equal & Opposite Forces
    bodyA.applyForce(springForce); // A Pulled Towards B
    bodyB.applyForce(-springForce); // B Pulled Towards A
}

// Step Simulation
void World::step(float dt) noexcept {
    // Clear Forces & Simulate Particles Under Gravity
    for (Particle& body : particles) {
        body.clearForces(); // Reset Forces For Next Frame
        body.applyForce(gravity * body.mass); // Apply World Gravity (W = m * g)
    }
    // Simulate Spring Connections (With Pairs of Particles)
    for (const Spring& spring : springs) {
        applySpringForce(spring); // Apply Spring Constraints (F = -kx)
    }
        
    // Integrate Particle Motion
    for (Particle& body : particles) {
        body.integrate(dt);
    }

    // Resolve Collisions (Between Particles and Plane Colliders)
    for (Particle& body : particles) {
        for (PlaneCollider& plane : planes) {
            float distance = dot(plane.normal, body.position) - plane.offset; // Signed Shortest Distance Between Body and Plane (Along Plane's Normal Axis)
            // Event: Body Penetrates Plane
            if (distance <= 0.0f) {
                float vNormal = dot(body.velocity, plane.normal); // Scalar Magnitude of (Component of) Body Velocity Acting Along Normal
                // Position Correction
                float constraintViolation = -distance; // (Penetration Depth = -distance)
                body.position += plane.normal * constraintViolation; // Teleport Body Out of Plane
                // Only Bounce IF Body Moving Into Plane
                if (vNormal < -PhysicsConstants::GROUND_EPSILON){ // Negative (Downward) Velocity Check
                    float bounceFactor = 1.0f + plane.restitution; // Scalar Proportion of Velocity: Current Kinetic Energy + Bounce Energy
                    float deltaVn = bounceFactor * vNormal; // Scalar Proportion * (Component of) Current Body Velocity Along Plane Normal
                    body.velocity -= (plane.normal * deltaVn); // Reverse Body's Normal Velocity and Apply Restitution (Energy Loss Due to Bounce)
                } else { // Remove Small Normal Velocity When In Resting Contact
                    body.velocity -= (plane.normal * vNormal);
                }

            }

        }
    }
    
}