#pragma once
#include "Window.hpp"
#include "Camera.hpp"
#include "src/engine/physics/World.hpp"

class Renderer {
    public:
        Renderer(Window& window, Camera& camera); // Constructor
        ~Renderer(); // Deconstructor

        // Core Functions
        void clear();
        void present();

        // Core Draw Functions
        void drawPoint(const Camera& camera, float x, float y, SDL_Color colour);
        void drawLine(const Camera& camera, float x1, float y1, float x2, float y2, SDL_Color colour);

        // World Draw Functions
        void drawParticles(const World& world, const Camera& camera);
        void drawPlanes(const World& world, const Camera& camera);
        void drawWorld(const World& world, const Camera& camera);

    private:
        SDL_Renderer* renderer = nullptr; // Renderer Pointer (Constructed Here)
        Window& window; // Window Reference (Initialised in Application.hpp)
        Camera& camera; // Camera Reference (Initialised in Application.hpp)

};