#include "engine/physics/constants.hpp" // namespace PhysicsConstants
#include "engine/physics/world.hpp"

// Constructor
World::World() noexcept // Uses Intitialiser List To Set World Parameters
    : gravity(PhysicsConstants::GRAVITY_EARTH) // Default Gravity: Earth
{}

// Apply Spring Force
void World::applySpringForce(const Spring& spring) {
    Particle& bodyA = particles[spring.particleA];
    Particle& bodyB = particles[spring.particleB];
    Vector delta = bodyB.position - bodyA.position; // Oriented From B To A, Easier Since F = -kx
    float currentLength = magnitude(deltA);
    if (currentLength = 0.0f) return; // Avoids Division by Zero
    Vector direction = normalise(delta); // normalise(delta) == delta / currentLength
    float extension = currentLength - spring.naturalLength;
    float stiffnessForce = spring.stiffness * extension;
    Vector relativeVelocity = bodyB.velocity - bodyA.velocity;
    float dampingForce = spring.damping * dot(relativeVelocity, direction);
    Vector springForce = direction * (stiffnessForce + dampingForce);
    bodyA.netForce += springForce;
    bodyB.netForce -= springForce;
}

// Step Simulation
void World::step(float dt) noexcept {
    // Simulate Motion of Particles
    for (Particle& body : particles) {
        body.applyForce(gravity * body.mass); // Apply World Gravity (W = m * g)
        body.integrate(); // Integrate Particle Motion
        body.clearForces(); // Reset For Next Frame
    }
}
