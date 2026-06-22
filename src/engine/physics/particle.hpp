#pragma once
#include "src/engine/maths/Vector.hpp"

// STRUCTURES //

struct Particle {
private:
    float mass; // Mass (Unit: kilograms, kg)
    float inverseMass; // (mass^-1 = 0 when mass -> infinity)

public:
    std::string name; // Printable Name of Particle

    Vector position; // Current Position (Unit: metres, m)
    Vector velocity; // Current Velocity (Unit: ms^-1)
    Vector acceleration; // Acceleration = netForce * inverseMass (Unit: ms^-2)

    Vector netForce; // Resultant Force (Unit: Newtons)

    Particle(float inMass = 1.0f, std::string inName = "DefaultParticle"):
        name(inName),
        mass(inMass),
        position(0,0),
        velocity(0,0),
        acceleration(0,0),
        netForce(0,0)
    {
        if (mass == 0.0f) // Infinite Mass
            inverseMass = 0.0f;
        else
            inverseMass = 1.0f / mass;
    }

    inline void setMass(float inMass) {
        mass = inMass;
        inverseMass = (inMass == 0.0f ? 0.0f : 1.0f / inMass);
    }

    // Apply New Force
    inline void applyForce(const Vector& force) noexcept {
        netForce += force;
    }

    // Clear All Forces
    inline void clearForces() noexcept {
        netForce = {0.0f, 0.0f};
    }

    // Integrate Particle Motion
    inline void integrate(float dt) noexcept {
    if (inverseMass == 0.0f) return; // Special Case: Infinite Mass
    acceleration = netForce * inverseMass; // Compute Acceleration (From Overall Force)
    // Semi-Implicit Euler
    velocity += acceleration * dt; // Update Particle Velocity
    position += velocity * dt; // Update Particle Position
    }

};
