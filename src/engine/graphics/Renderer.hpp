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

        static constexpr float PPM = 12.0f; // Unit Conversion: 12.0px = 1.0m

        int projectX(float metresX) const; // Project: world_x -> screen_x
        int projectY(float metresY) const; // Project: world_y -> screen_y
};