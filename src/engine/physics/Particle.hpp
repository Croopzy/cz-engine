#pragma once
#include "src/engine/maths/Vector.hpp"
#include "src/engine/core/Visuals.hpp"


struct ParticleVisuals {
    float radius = 2.5f;
    bool fill = true;
    bool trail = false;
    int stepT = 60; // Step Number When Trail Rendered
};


struct Particle {
private:
    float mass; // Mass (Unit: kilograms, kg)
    float inverseMass; // (mass^-1 = 0 when mass -> infinity)

public:
    Vector position; // Current Position (Unit: metres, m)
    Vector velocity; // Current Velocity (Unit: ms^-1)
    Vector acceleration; // Acceleration = netForce * inverseMass (Unit: ms^-2)
    Vector netForce; // Resultant Force (Unit: Newtons)

    bool collisions; // Toggle Collisions with Particle

    BasicVisuals visuals; // General Visual Elements
    ParticleVisuals extraVisuals; // Visual Elements Specific To Particles

    std::string name; // Printable Name of Particle

    // Particle Constructor
    Particle(float inMass = 0.0f,
        const std::string& inName = "DefaultParticle",
        Vector inPosition = Vector(0.0f, 0.0f),
        bool toggle = true
    );

    inline void setMass(float inMass) {
        mass = inMass;
        inverseMass = (inMass == 0.0f ? 0.0f : 1.0f / inMass); // Condensed Repetition of Constructor Body
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

    inline void setVelocity(float inX, float inY) {
        velocity.x = inX;
        velocity.y = inY;
    }

    inline void project(float angle, float speed) {
        velocity = resolve(angle, speed);
    }

    // Apply New Force
    inline void applyForce(const Vector& force) noexcept {
        netForce += force;
    }

    // Clear All Forces
    inline void clearForces() noexcept {
        netForce = {0.0f, 0.0f};
    }

    // Velocity Verlet Integration
    void integratePosition(float dt) noexcept;
    void integrateVelocity(float dt) noexcept;

};
