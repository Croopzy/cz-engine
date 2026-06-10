#pragma once
#include "Renderer.hpp"

class Application {
    public:
        Application();
        void run();
    private:
        Window window;
        Renderer renderer;
};