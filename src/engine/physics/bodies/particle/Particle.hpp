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
public:
    PointMass internal;

    bool collisions; // Toggle Collisions with Particle

    ParticleVisuals extraVisuals; // Visual Elements Specific To Particles
    std::string name; // Printable Name of Particle

    // Particle Constructor
    Particle(float inMass = 0.0f, const std::string& inName = "DefaultParticle", Vector inPosition = Vector(0.0f, 0.0f), bool toggle = true)
        : internal(inMass, inPosition), name(inName) {}
};
