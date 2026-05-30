#pragma once
#include "engine/maths/vector.hpp"
#include "engine/physics/particle.hpp"

// Spring Structure (Binary Force Connecting Two Particles)
struct Spring {
    // World Indices of Connected Particles
    int particleA;
    int particleB;
    // Spring Properties
    float naturalLength; // Unaltered Spring 'Length'
    float stiffness; // Resistance To Stretching or Compression
    float damping; // Resistance To Relative Motion

    // Spring Constructor
    Spring(int a, int b, float l, float k, float d)
        : particleA(a),
          particleB(b),
          naturalLength(l),
          stiffness(k),
          damping(d)
    {}
};


// World Class: Contains the physics environment, its bodies and its rules
class World {
public:
    
    // World Parameters
    Vector gravity;

    // World Bodies
    std::vector<Particle> particles; // Collection of Particles in World

    // World Springs
    std::vector<Spring> springs; // Collection of Particles in World

    /// Methods ///

    // World Constructor
    World() noexcept;

    // Step Function Declaration
    void step(float dt) noexcept;

    // Create New Particle in World (Function)
    inline Particle& addParticle(float mass) { 
        particles.emplace_back(mass); // Constructs Particle Directly Inside Particles Vector
        return particles.back(); // Returns Reference to New Particle
    }

    // Create New Spring in World (Function)
    inline void addSpring(int particleA, int particleB, float naturalLength, float stiffness, float damping) {
        springs.emplace.back(particleA, particleB, naturalLength, stiffness, damping) // Constructor
    }
};