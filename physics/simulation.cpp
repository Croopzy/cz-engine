#include "physics/simulation.hpp"
#include "physics/constants.hpp" // PhysicsConstants

void Simulation::step(float dt) noexcept {
    for (Particle& body : particles) {

        // Apply World Gravity (F = m * g)
        body.netForce += gravity * p.mass;

        // Integrate (Semi-Implicit Euler)
        body.acceleration = p.netForce * p.inverseMass; // Unit: ms^-2
        body.velocity += p.acceleration * dt;           // Unit: m/s
        body.position += p.velocity * dt;               // Unit: metres

        // Reset For Next Frame
        body.netForce = Vector{0.0f, 0.0f};
    }
}
