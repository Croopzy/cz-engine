#pragma once
#include "src/simulations/Scenario.hpp"

class FreefallScenario : public Scenario { // Child Class of Scenario
    public:
        FreefallScenario(int numSteps = 600);

        void start() override;
        void poll() override;
        void end() override;

    private:
        World& earth = getWorld();
        int apple = earth.addParticle(10.0f, "Apple", Vector(0.0f, 100.0f)); // Create Apple (Mass = inMass) in Earth Simulation, Default: Infinite Mass
        bool groundContact = false;
};