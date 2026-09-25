#pragma once
#include <vector>
#include "src/Cryoze/core/Visuals.hpp"
#include "src/Cryoze/physics/bodies/particle/Particle.hpp"

enum class ParticleID : int; // Forward Declaration

// Spring Structure (Binary Force Connecting Two Particles)
struct Spring {
    public:
    BasicVisuals visuals;

    // World Indices of Connected Particles
    ParticleID particleA;
    ParticleID particleB;
    
    // Spring Properties
    float naturalLength; // Unaltered Spring 'Length'
    float stiffness; // Resistance To Stretching or Compression
    float damping; // Resistance To Relative Motion

    // Spring Constructor
    Spring(ParticleID a, ParticleID b, float l, float k, float d)
        : particleA(a),
          particleB(b),
          naturalLength(l),
          stiffness(k),
          damping(d)
    {}

    // Apply Spring Force on Connected Particles
    void applyForce(std::vector<Particle>& particles);

};
