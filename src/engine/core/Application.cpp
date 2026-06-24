#include "Application.hpp"
#include <chrono>
#include <thread>


Application::Application()
    : window("Cryoze Engine", DEFAULT_WIDTH, DEFAULT_HEIGHT),
    camera(Vector(0, 0), 1.0f, DEFAULT_WIDTH, DEFAULT_HEIGHT),
    renderer(window, camera) {
}


void Application::run(Scenario& scenario, bool visualiserEnabled) {

    scenario.start();

    bool visualiserActive = true;
    SDL_Event event;

    for (int i = 0; i < scenario.numSteps; ++i) {

        while (SDL_PollEvent(&event)) { // Always Poll Events
            if (event.type == SDL_EVENT_QUIT) visualiserActive = false;
        }

        scenario.step(); // Step Physics

        scenario.poll(); // Handle Events

        if (visualiserEnabled && visualiserActive) {
            renderFrame(scenario); // Render Frame
        }

    }

    scenario.end();
}