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
        renderer.drawWorld(world, camera);
        renderer.present();
    }
}