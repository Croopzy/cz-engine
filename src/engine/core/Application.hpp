#pragma once
#include "src/engine/physics/World.hpp"
#include "src/engine/graphics/Renderer.hpp"
#include "src/simulations/Scenario.hpp"

class Application {
    public:
        Application();

        void run(Scenario& scenario, bool visualiser);

    private:
        // Visualiser Components
        Window window;
        Camera camera;
        Renderer renderer;

        // Window
        static constexpr int DEFAULT_WIDTH = 1200;
        static constexpr int DEFAULT_HEIGHT = 720;

        // Timestep
        static constexpr float DT = PhysicsConstants::FIXED_DT;

        // Render Frame
        void renderFrame(Scenario& scenario) {
            renderer.clear();
            renderer.drawWorld(scenario.getWorld(), camera);
            renderer.present();
        }
};