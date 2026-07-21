#pragma once
#include <memory>
#include "src/engine/core/Visualiser.hpp"
#include "src/simulations/Scenario.hpp"

// Forward Declarations
class Window;
class Camera;
class Renderer;
class Visualiser;


class Application {
    public:
        Application() {};

        void run(Scenario& scenario, bool visualiserEnabled = true);

    private:
        // Graphics Member Declarations
        std::unique_ptr<Window> window;
        std::unique_ptr<Camera> camera;
        std::unique_ptr<Renderer> renderer;

        // Core Member Declarations
        std::unique_ptr<Visualiser> visualiser;

        // Define Window
        static constexpr int DEFAULT_WIDTH = 1280;
        static constexpr int DEFAULT_HEIGHT = 720;

        // Render Frame
        void renderFrame(Scenario& scenario);
};
