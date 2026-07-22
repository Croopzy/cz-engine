#pragma once
#include "src/engine/graphics/window/Window.hpp"
#include "src/engine/graphics/camera/Camera.hpp"

class Renderer {
    public:
        Renderer(Window& window, Camera& camera); // Constructor
        ~Renderer(); // Destructor

        // Core Functions
        void clear();
        void present();

        // Core Draw Functions
        void drawPoint(const Camera& camera, float x, float y, SDL_Color colour  = SDL_Color{255, 255, 255, 255});
        void drawLine(const Camera& camera, float x1, float y1, float x2, float y2, SDL_Color colour  = SDL_Color{255, 255, 255, 255});
        void drawCircle(const Camera& camera, float centreX, float centreY, float radius, bool fillEnabled = false, SDL_Color colour  = SDL_Color{255, 255, 255, 255});

    private:
        SDL_Renderer* renderer = nullptr; // Renderer Pointer (Constructed Here)
        Window& window; // Window Reference (Initialised in Application.hpp)

};
