#pragma once
#include "src/Cryoze/simulation/Scenario.hpp"
#include "src/Cryoze/physics/bodies/particle/ParticleHandle.hpp"

class Oscillator : public Scenario { // Child Class of Scenario
    public:
        Oscillator(int numSteps = 900);

        void start() override;
        void poll() override;
        void end() override;

    private:
        std::string scenarioName = "DAMPED HARMONIC MOTION";
        World& earth;
        ParticleHandle anchor{earth};
        ParticleHandle bob{earth};
};