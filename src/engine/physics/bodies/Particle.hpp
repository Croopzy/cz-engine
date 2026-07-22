#pragma once
#include "src/engine/maths/Vector.hpp"
#include "src/engine/core/Visuals.hpp"
#include "src/engine/physics/bodies/point_mass/PointMass.hpp"

struct ParticleVisuals {
    float radius = 0.25f;
    bool fill = true;
    bool trail = false;
    int trailPeriod = 60; // Step Number When Trail Rendered
    float trailRadius = 0.1;
};


struct Particle {
public:
    PointMass& linear() { return linearState; }; // Composition
    const PointMass& linear() const { return linearState; }; // Const Accessor

    ParticleVisuals extraVisuals{}; // Visual Elements Specific To Particles
    std::string name; // Printable Name of Particle

    bool collisions; // Enable or Disable Collisions with Particle

    // Particle Constructor
    explicit Particle(float inMass = 0.0f, const std::string& inName = "DefaultParticle", Vector inPosition = Vector(0.0f, 0.0f), bool toggle = true)
        : linearState(inMass, inPosition), name(inName), collisions(toggle) {}
private:
    PointMass linearState;
};
