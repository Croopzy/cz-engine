#pragma once
#include "src/simulations/Scenario.hpp"

class Freefall : public Scenario { // Child Class of Scenario
public:
    Freefall(); // Constructor
    void runScenario() override; // Polymorphic Override of Function in Scenario Class

private:
    void start() override;

    World& earth = getWorld();
    Particle& apple = earth.addParticle(0); // Create Apple (Mass = inMass) in Earth Simulation, Default: Infinite Mass

    bool contact = false;
    void step(int i) override; // Use Fixed Step Implementation

    void end() override;
};