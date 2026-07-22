#pragma once
#include "src/simulations/Scenario.hpp"

class Freefall : public Scenario { // Child Class of Scenario
    public:
        Freefall(int numSteps = 900);

        void start() override;
        void poll() override;
        void end() override;

        float zoom = 2.5;

    private:
        World& earth = getWorld();
        int apple;
        bool groundContact = false;
};
