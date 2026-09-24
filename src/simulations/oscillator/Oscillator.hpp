#pragma once
#include "src/simulations/Scenario.hpp"

class Oscillator : public Scenario { // Child Class of Scenario
    public:
        Oscillator(int numSteps = 900);

        void start() override;
        void poll() override;
        void end() override;

    private:
        std::string scenarioName = "DAMPED HARMONIC MOTION";
        World& earth;
        int anchor;
        int bob;
};