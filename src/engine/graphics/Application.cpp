#include "Application.hpp"


Application::Application()
    : window("Cryoze Engine", DEFAULT_WIDTH, DEFAULT_HEIGHT),
    world(),
    camera(Vector(0, 0), 1.0f, DEFAULT_WIDTH, DEFAULT_HEIGHT),
    renderer(window, camera) {
    }

void Application::run() {
    bool active = true;
    SDL_Event event;

    while (active) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) active = false;
        }

        renderer.clear();

        // TEST DRAWING
        renderer.drawLine(camera, 0, 50, 100, 50, SDL_Color{255, 255, 255, 255}); // Draw White Line Along y = 100m
        renderer.drawPoint(camera, 50, 100, SDL_Color{255, 0, 0, 255}); // Draw Red Point At (50, 100)m in Cartesian Plane (x, y)

        renderer.present();
    }
}