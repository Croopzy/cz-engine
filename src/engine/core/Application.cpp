#include "Application.hpp"
#include <chrono>
#include <thread>


Application::Application()
    : window("Cryoze Engine", DEFAULT_WIDTH, DEFAULT_HEIGHT),
    camera(Vector(0, 0), 2.5, DEFAULT_WIDTH, DEFAULT_HEIGHT),
    renderer(window, camera),
    visualiser(renderer) {
}

void Application::run(Scenario& scenario, bool visualiserEnabled) {

    scenario.start();

    if (visualiserEnabled) {
        renderFrame(scenario); // Render Initial Frame
    }
    bool visualiserActive = true;

    SDL_Event event;

    auto nextTick = std::chrono::high_resolution_clock::now();
    auto delay = std::chrono::duration<float>(scenario.dt);
    auto nativeDelay = std::chrono::duration_cast<std::chrono::high_resolution_clock::duration>(delay);
    
    for (int i = 0; i < scenario.numSteps; ++i) {

        while (SDL_PollEvent(&event)) { // Always Poll Events
            if (event.type == SDL_EVENT_QUIT) visualiserActive = false;
        }

        // Update Scenario
        scenario.step(); // Step Physics

        scenario.poll(); // Handle Events

        // Render Scenario
        if (visualiserEnabled && visualiserActive) {
            renderFrame(scenario); // Render Frame
        }

        // Maintain Fixed Timestep
        auto now = std::chrono::high_resolution_clock::now();
        if (now < nextTick) { // EVENT: Clock Behind
            std::this_thread::sleep_until(nextTick); // Skip Delay
        }
        nextTick += nativeDelay;

    }

    scenario.end();
    
    // PRESS ENTER TO TERMINATE SCENARIO
    std::cout << "\n\nPRESS ENTER TO END SIMULATION ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get(); // Await Input: ENTER
}