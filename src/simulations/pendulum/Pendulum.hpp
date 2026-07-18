#pragma once
#include "src/simulations/Scenario.hpp"

class Pendulum : public Scenario { // Child Class of Scenario
    public:
        Pendulum(int numSteps = 900);

        void start() override;
        void poll() override;
        void end() override;

    private:
        World& earth;
        int pivot;
        int bob;
};
