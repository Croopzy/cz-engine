#pragma once
#include "src/engine/graphics/Renderer.hpp"

class Application {
    public:
        Application();

        void run(World& world);

    private:
        // Visualiser Setup
        Window window;
        Camera camera;
        Renderer renderer;
        static constexpr int DEFAULT_WIDTH = 1200;
        static constexpr int DEFAULT_HEIGHT = 720;

        // Timestep
        static constexpr float FIXED_DT = 1.0f / 60.0f;
};