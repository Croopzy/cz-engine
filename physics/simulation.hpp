#pragma once
#include "maths/vector.hpp"
#include "physics/particle.hpp"

// Worlds Class: Contains the physics environment, its bodies and its rules
class Simulation {
public:
    
    // World Parameters
    Vector gravity;

    // Bodies in World (Collections)
    std::vector<Particle> particles;

    // Methods
    Simulation() noexcept;
    void step(float dt) noexcept;
};
