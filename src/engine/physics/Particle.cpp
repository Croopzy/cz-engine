#include "Particle.hpp"
#include <algorithm>

// Particle Constructor
Particle::Particle(float inMass, const std::string& inName, Vector inPosition, bool toggle)
    : mass(inMass),
      position(inPosition.x, inPosition.y),
      velocity(0.0f, 0.0f),
      acceleration(0.0f, 0.0f),
      netForce(0.0f, 0.0f),
      name(inName),
      collisions(toggle)
{
    updateInverseMass();
}

void Particle::updateInverseMass() noexcept {
    mass = std::max(0.0f, mass); // Clamp Mass >= 0
    inverseMass = (mass == 0.0f) ? 0.0f : (1.0f / mass);
}

// Velocity Verlet Integration
void Particle::integratePosition(float dt) noexcept {
    if (inverseMass == 0.0f) return; // Special Case: Infinite Mass
    acceleration = netForce * inverseMass; // Compute Acceleration (From Overall Force)
    position += (velocity * dt) + (0.5f * acceleration * dt * dt); // Update Particle Position
}

void Particle::integrateVelocity(float dt) noexcept {
    if (inverseMass == 0.0f) return; // Special Case: Infinite Mass
    Vector newAcceleration = netForce * inverseMass; // Compute Acceleration (From New Net Force)
    velocity += (0.5f * (acceleration + newAcceleration) * dt); // Update Particle Velocity
    acceleration = newAcceleration; // Update Stored Acceleration for Next Frame
}