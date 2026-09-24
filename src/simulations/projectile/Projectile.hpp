#pragma once
#include "src/simulations/Scenario.hpp"

class Projectile : public Scenario { // Child Class of Scenario
    public:
        Projectile(int numSteps = 900);

        void start() override;
        void poll() override;
        void end() override;

    private:
        std::string scenarioName = "PROJECTILE MOTION";
        World& earth;
        int apple;
        bool groundContact = false;
};
