#pragma once
#include "src/engine/physics/World.hpp"
#include <iostream>

class Scenario { // Base Class (No Independent Constructor)
    public:
        virtual ~Scenario() = default; // 'virtual': Explicitly Enables Polymorphism, 'default': Compiler Generates Destructor Body

        World& getWorld() { return world; }

        virtual void start() {
            std::cout << "SIMULATION INITIALISED" << "\n\n";
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
        int zoom = 25; // Default Zoom = 25 PPM (Pixels Per Metre)


    protected:
        int stepID = 0;

    private:
        World world;
};