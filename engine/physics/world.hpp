#pragma once
#include "engine/maths/vector.hpp"
#include "engine/physics/particle.hpp"

// World Class: Contains the physics environment, its bodies and its rules
class World {
public:
    
    // World Parameters
    Vector gravity;

    // World Bodies
    std::vector<Particle> particles; // Collection of Particles in World


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

};
