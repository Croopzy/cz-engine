#pragma once
#include "src/engine/physics/World.hpp"

class Scenario {
    public:
        virtual ~Scenario() = default; // 'virtual': Explicitly Enables Polymorphism, 'default': Compiler Generates Destructor Body

        virtual void runScenario() {
            start();
            for (int stepID = 0; stepID < steps; ++stepID) {
                step(stepID);
            }
            end();
        }

    protected:

        World& getWorld() { return world; }

        virtual void start() = 0; // 'Virtual ... = 0': Purely Virtual Function (Only Child Classes Define This Function)

        float dt = PhysicsConstants::FIXED_DT;
        int steps = 1;

        virtual void step() {} // Single Step (Primarily For Event-Driven Scenarios)
        virtual void step(int stepID  ) { step(); } // Fixed Step (Set Number of Steps)

        virtual void end() = 0;

    private:
        World world;
};