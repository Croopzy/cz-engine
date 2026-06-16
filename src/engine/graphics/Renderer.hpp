#pragma once
#include "Window.hpp"
#include "Camera.hpp"

class Renderer {
    public:
        Renderer(Window& window, Camera& camera); // Constructor
        ~Renderer(); // Deconstructor

        // Core Functions
        void clear();
        void present();

        // Draw Functions
        void drawPoint(Camera& camera, float x, float y, SDL_Color colour);
        void drawLine(Camera& camera, float x1, float y1, float x2, float y2, SDL_Color colour);


    private:
        SDL_Renderer* renderer = nullptr; // Renderer Pointer (Constructed Here)
        Window& window; // Window Reference (Initialised in Application.hpp)
        Camera& camera; // Camera Reference (Initialised in Application.hpp)


};