#include "engine/physics/constants.hpp" // namespace PhysicsConstants
#include "engine/physics/world.hpp"

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
    // Hooke's Law (Scalar)
    float stiffnessForce = spring.stiffness * extension;
    // Damping (Scalar)
    Vector relativeVelocity = bodyB.velocity - bodyA.velocity;
    float dampingForce = spring.damping * dot(relativeVelocity, direction);
    // Net Vector Force (A -> B)
    Vector springForce = direction * (stiffnessForce + dampingForce); // Vector * Sum of Scalars
    // Apply Equivalent & Opposite Forces
    bodyA.applyForce(springForce);
    bodyB.applyForce(-springForce);
}

// Step Simulation
void World::step(float dt) noexcept {
    // Simulate Particles Under Gravity
    for (Particle& body : particles) {
        body.clearForces(); // Reset Forces For Next Frame
        body.applyForce(gravity * body.mass); // Apply World Gravity (W = m * g)
    }
    // Simulate Spring Connections To Particles
    for (Spring& spring : springs) {
        applySpringForce(spring); // Apply Spring Constraints (F = -kx)
    }
    
    for (Particle& body : particles) {
        body.integrate(dt); // Integrate Particle Motion
    }
    
}