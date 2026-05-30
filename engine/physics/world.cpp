#include "engine/physics/constants.hpp" // namespace PhysicsConstants
#include "engine/physics/world.hpp"

// Constructor
World::World() noexcept // Uses Intitialiser List To Set World Parameters
    : gravity(PhysicsConstants::GRAVITY_EARTH) // Default Gravity: Earth
{}

// Step Simulation
void World::step(float dt) noexcept {
    // Simulate Motion of Particles
    for (Particle& body : particles) {
        body.applyForce(gravity * body.mass); // Apply World Gravity (W = m * g)
        body.integrate(); // Integrate Particle Motion
        body.clearForces(); // Reset For Next Frame
    }
}
