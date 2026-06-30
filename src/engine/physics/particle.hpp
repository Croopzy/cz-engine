#pragma once
#include "src/engine/maths/Vector.hpp"
#include "src/engine/core/Visuals.hpp"

// STRUCTURES //

struct ParticleVisuals {
    bool fill = true;
    float radius = 5.00f;
};


struct Particle {
private:
    float mass; // Mass (Unit: kilograms, kg)
    float inverseMass; // (mass^-1 = 0 when mass -> infinity)

public:
    BasicVisuals visuals;
    ParticleVisuals extraVisuals;

    std::string name; // Printable Name of Particle

    Vector position; // Current Position (Unit: metres, m)
    Vector velocity; // Current Velocity (Unit: ms^-1)
    Vector acceleration; // Acceleration = netForce * inverseMass (Unit: ms^-2)

    Vector netForce; // Resultant Force (Unit: Newtons)

    Particle(float inMass = 0.0f, std::string inName = "DefaultParticle", Vector inPosition = Vector(0.0f, 0.0f)): // Default: Fixed Immovable Point (Infinite Mass)
        name(inName),
        mass(inMass),
        position(inPosition.x, inPosition.y),
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

    inline float getMass() const { return mass; }
    inline float getInverseMass() const { return inverseMass; }

    inline void setPosition(float inX, float inY) {
        position.x = inX;
        position.y = inY;
    }

    inline void setHeight(float inHeight) {
        position.y = inHeight;
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
