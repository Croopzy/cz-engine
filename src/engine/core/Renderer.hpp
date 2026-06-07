#pragma once
#include "Window.hpp"

class Renderer {
    public:
        Renderer(Window& window);
        ~Renderer();

        void clear();
        void present();

        void drawPoint(int x, int y, SDL_Color colour);
        void drawLine(int x1, int y1, int x2, int y2, SDL_Color colour);


    private:
        SDL_Renderer* renderer = nullptr;
};