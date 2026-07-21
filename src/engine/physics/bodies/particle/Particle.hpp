#pragma once
#include "src/engine/maths/Vector.hpp"
#include "src/engine/core/Visuals.hpp"


struct ParticleVisuals {
    float radius = 0.25f;
    bool fill = true;
    bool trail = false;
    int trailPeriod = 60; // Step Number When Trail Rendered
    float trailRadius = 0.1;
};


struct Particle {
private:
    float mass; // Mass (Unit: kilograms, kg)

    float inverseMass; // (mass^-1 = 0 when mass -> infinity)
    void updateInverseMass() noexcept;

    Vector netForce; // Resultant Force (Unit: Newtons)

public:
    Vector position; // Current Position (Unit: metres, m)
    Vector velocity; // Current Velocity (Unit: ms^-1)
    Vector acceleration; // Acceleration = netForce * inverseMass (Unit: ms^-2)

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
        updateInverseMass();
    }

    inline float getMass() const { return mass; }
    inline float getInverseMass() const { return inverseMass; }
        

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
