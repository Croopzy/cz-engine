#pragma once
#include "maths/vector.hpp"
#include "physics/particle.hpp"

// World Class: Contains the physics environment, its bodies and its rules
class World {
public:
    
    // World Parameters
    Vector gravity;

    // World Bodies
    std::vector<Particle> particles; // Collection of Particles in World

    // Methods
    World() noexcept; // World Constructor
    void step(float dt) noexcept;
};
