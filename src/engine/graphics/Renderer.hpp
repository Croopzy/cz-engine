#pragma once
#include "Window.hpp"

class Renderer {
    public:
        Renderer(Window& window);
        ~Renderer();

        void clear();
        void present();

        void drawPoint(float x, float y, SDL_Color colour);
        void drawLine(float x1, float y1, float x2, float y2, SDL_Color colour);


    private:
        SDL_Renderer* renderer = nullptr;
        Window& window;

        static constexpr float PPM = 50.0f; // Unit Conversion: 1.0m = 50.0px

        int projectX(float metres) const; // Project: world_x -> screen_x
        int projectY(float metres) const; // Project: world_y -> screen_y
};