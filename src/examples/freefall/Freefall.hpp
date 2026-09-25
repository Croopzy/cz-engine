#pragma once
#include "src/Cryoze/simulation/Scenario.hpp"
#include "src/Cryoze/physics/bodies/particle/ParticleHandle.hpp"

class Freefall : public Scenario { // Child Class of Scenario
    public:
        Freefall(int numSteps = 900);

        void start() override;
        void poll() override;
        void end() override;

        float zoom = 2.5;

    private:
        std::string scenarioName = "FREEFALL";
        World& earth;
        ParticleHandle apple{earth};
        bool groundContact = false;
};
