#include "Application.hpp"
#include <chrono>
#include <thread>


Application::Application()
    : window("Cryoze Engine", DEFAULT_WIDTH, DEFAULT_HEIGHT),
    camera(Vector(0, 0), 1.0f, DEFAULT_WIDTH, DEFAULT_HEIGHT),
    renderer(window, camera) {
    }

void Application::run(Scenario& scenario, bool visualiser = true) {

    scenario.start();
    bool active = true;

    SDL_Event event;
    while (active) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) active = false;
        }

        for (int stepID = 0; stepID < scenario.numSteps; ++stepID) {
            scenario.step(stepID); // Step Physics

            scenario.poll(); // Handle Events

            if (visualiser == true) {
                renderFrame(scenario); // Render Frame
            }
        }
    }

    scenario.end();
}