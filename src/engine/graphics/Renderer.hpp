#pragma once
#include "Window.hpp"

class Renderer {
    public:
        Renderer(Window& window); // Constructor
        ~Renderer(); // Deconstructor

        // Core Functions
        void clear();
        void present();

        // Draw Functions
        void drawPoint(float x, float y, SDL_Color colour);
        void drawLine(float x1, float y1, float x2, float y2, SDL_Color colour);


    private:
        SDL_Renderer* renderer = nullptr; // Renderer Pointer (Constructed Here)
        Window& window; // Window Reference (Constructed in Window Files)

        // World Projection
        static constexpr float PPM = 12.0f; // Unit Conversion: 12.0px = 1.0m
        int projectX(float metresX) const; // Project: world_x -> screen_x
        int projectY(float metresY) const; // Project: world_y -> screen_y
};