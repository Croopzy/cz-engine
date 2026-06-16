#pragma once
#include "src/engine/graphics/Renderer.hpp"

class Application {
    public:
        Application();
        void run();
    private:
        World world;
        Window window;
        Camera camera;
        Renderer renderer;
        static constexpr int DEFAULT_WIDTH = 1200;
        static constexpr int DEFAULT_HEIGHT = 720;
};