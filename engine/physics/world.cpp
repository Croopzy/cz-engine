#include "constants.hpp" // namespace PhysicsConstants
#include "world.hpp"

// Constructor
World::World() noexcept // Uses Intitialiser List To Set World Parameters
    : gravity(PhysicsConstants::GRAVITY_EARTH) // Default Gravity: Earth
{}

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
    float vParallel = dot(relativeVelocity, direction); // This changes the extension because its direction is parallel to the spring
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
    
    for (Particle& body : particles) {
        body.integrate(dt); // Integrate Particle Motion
    }
    
}