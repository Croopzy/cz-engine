#pragma once
#include <SDL3/SDL.h>

class Window {
    public:
        Window(const char* title, int width, int height); // Unit (of Width, Height): px
        ~Window();

        SDL_Window* get() const { return window; }

    private:
        SDL_Window* window = nullptr;
};