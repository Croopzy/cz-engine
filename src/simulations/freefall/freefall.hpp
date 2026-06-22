#pragma once
#include "src/simulations/Scenario.hpp"

class Freefall : public Scenario { // Child Class of Scenario
public:
    void runScenario() override; // Polymorphic Override of Function in Scenario Class

private:
    void start() override;
    void step(int i) override; // Use Fixed Step Implementation
    void end() override;

    World& earth = getWorld();
};