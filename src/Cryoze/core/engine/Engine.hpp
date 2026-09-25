#pragma once
#include <memory>
#include "src/Cryoze/core/visualiser/Visualiser.hpp"
#include "src/Cryoze/simulation/Scenario.hpp"

// Forward Declarations
class Window;
class Camera;
class Renderer;
class Visualiser;


class Engine {
    public:
        Engine() {};

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
