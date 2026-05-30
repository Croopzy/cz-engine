#pragma once
#include "maths/vector.hpp"
#include "physics/particle.hpp"

class Simulation {
public:
    std::vector<Particle> particles;

    void step(float dt) noexcept;
};
