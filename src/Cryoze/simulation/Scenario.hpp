#pragma once
#include "src/Cryoze/physics/world/World.hpp"
#include <iostream>
#include <string>

class Scenario { // Base Class (No Independent Constructor)
    public:
        virtual ~Scenario() = default; // 'virtual': Explicitly Enables Polymorphism, 'default': Compiler Generates Destructor Body

        World& getWorld() { return world; }

        virtual void start() {
            std::cout << "SIMULATION INITIALISED: " << scenarioName << "\n\n";
            world.printInfo(false);
        }

        int numSteps = 1;
        const float dt = PhysicsConstants::FIXED_DT;

        virtual void step() {
            world.step(dt);
            stepID++;
        }

        virtual void poll() {} // Default Empty

        virtual void end() {
            std::cout << "\n\nSimulation Concluded"
            << "\n- Time: " << (numSteps * dt) << "s";
        }

        // Visualiser Settings
        float zoom = 25; // Default Zoom = 25 PPM (Pixels Per Metre)
        float camX = 0; // Unit: Metres (From Origin)
        float camY = 0; // Unit: Metres (From Origin)


    protected:
        std::string scenarioName = "NEW SIMULATION";
        int stepID = 0;

    private:
        World world;
};