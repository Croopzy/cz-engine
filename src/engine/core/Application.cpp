#include "Application.hpp"
#include <chrono>
#include <thread>


Application::Application()
    : window("Cryoze Engine", DEFAULT_WIDTH, DEFAULT_HEIGHT),
    camera(Vector(0, 0), 1.0f, DEFAULT_WIDTH, DEFAULT_HEIGHT),
    renderer(window, camera) {}

void Application::run(Scenario& scenario, bool visualiser) {

    scenario.start();
    bool active = true;

    SDL_Event event;
    while (active) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) active = false;
        }

        for (int i = 0; i < scenario.numSteps; ++i) {
            scenario.step(); // Step Physics

            scenario.poll(); // Handle Events

            if (visualiser == true) {
                renderFrame(scenario); // Render Frame
            }
        }
    }

    scenario.end();
}