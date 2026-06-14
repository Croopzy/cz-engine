#pragma once
#include <SDL3/SDL.h>

class Window {
    public:
        Window(const char* title, int width, int height); // Constructor, Parameter Units [Width, Height]: px
        ~Window(); // Deconstructor Declaration

        SDL_Window* getSDLWindow() const;

        int getWidth() const;
        int getHeight() const;

        void setWidth(int newWidth);
        void setHeight(int newHeight);

    private:
        SDL_Window* window = nullptr;
        int width = 1200;
        int height = 720;
};