#pragma once
#include "Renderer.hpp"

class Application {
    public:
        Application();
        void run();
    private:
        Window window;
        Renderer renderer;
        static constexpr int DEFAULT_WIDTH = 1200;
        static constexpr int DEFAULT_HEIGHT = 720;
};