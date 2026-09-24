#pragma once
#include "src/simulations/Scenario.hpp"
#include <optional>

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
        std::optional<ParticleID> appleID;
        PointMass& apple() { return earth.getParticle(appleID.value()).linear(); }
        bool groundContact = false;
};
