#include "physics/simulation.hpp"
#include "physics/constants.hpp" // PhysicsConstants

// Constructor
Simulation::Simulation() noexcept
    : gravity(PhysicsConstants::GRAVITY_EARTH) // Uses Intitialiser List To Set World Parameters
{}

// Apply Step
void Simulation::step(float dt) noexcept {
    for (Particle& body : particles) {

        // Apply World Gravity (F = m * g)
        body.netForce += gravity * body.mass;

        // Integrate (Semi-Implicit Euler)
        body.acceleration = body.netForce * body.inverseMass; // Unit: ms^-2
        body.velocity += body.acceleration * dt; // Unit: m/s
        body.position += body.velocity * dt; // Unit: metres

        // Reset For Next Frame
        body.netForce = Vector{0.0f, 0.0f};
    }
}
