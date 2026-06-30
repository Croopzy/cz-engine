#pragma once
#include "src/engine/core/Visualiser.hpp"
#include "src/simulations/Scenario.hpp"

class Application {
    public:
        Application();

        void run(Scenario& scenario, bool visualiserEnabled = true);

    private:
        // Graphics Member Declarations
        Window window;
        Camera camera;
        Renderer renderer;

        // Core Member Declarations
        Visualiser visualiser;

        // Define Window
        static constexpr int DEFAULT_WIDTH = 1200;
        static constexpr int DEFAULT_HEIGHT = 720;

        // Render Frame
        void renderFrame(Scenario& scenario) {
            renderer.clear();
            visualiser.drawWorld(scenario.getWorld(), camera);
            renderer.present();
        }
};