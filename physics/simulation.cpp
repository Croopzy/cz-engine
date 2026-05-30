#include "physics/world.hpp"
#include "physics/constants.hpp" // PhysicsConstants

// Constructor
World::World() noexcept // Uses Intitialiser List To Set World Parameters
    : gravity(PhysicsConstants::GRAVITY_EARTH) // Default Gravity: Earth
{}

// Step Simulation
void World::step(float dt) noexcept {
    for (Particle& body : particles) {

        // Apply World Gravity (F = m * g)
        body.netForce += gravity * body.mass;

        // Integrate (Semi-Implicit Euler)
        body.acceleration = body.netForce * body.inverseMass; // Unit: ms^-2
        body.velocity += body.acceleration * dt; // Unit: m/s
        body.position += body.velocity * dt; // Unit: metres

        // Reset For Next Frame
        body.clearForces();
    }
}
