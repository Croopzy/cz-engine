#include "Application.hpp"
#include <chrono>
#include <thread>

void Application::run(Scenario& scenario, bool visualiserEnabled) {

    scenario.start();

    // Create Window
    window = std::make_unique<Window>("Cryoze Engine", DEFAULT_WIDTH, DEFAULT_HEIGHT);
    // Create Camera
    camera = std::make_unique<Camera>(Vector(0, 0), scenario.zoom, DEFAULT_WIDTH, DEFAULT_HEIGHT);
    // Create Renderer
    renderer = std::make_unique<Renderer>(*window, *camera);
    // Create Visualiser
    visualiser = std::make_unique<Visualiser>(*renderer);

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
        while (now < nextTick) { // EVENT: Clock Behind
            SDL_Delay(1); // Yield To OS
            now = std::chrono::high_resolution_clock::now();
        }
        nextTick += nativeDelay;

    }

    scenario.end();
    
    // PRESS ENTER TO TERMINATE SCENARIO
    std::cout << "\n\nPRESS ENTER TO END SIMULATION ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get(); // Await Input: ENTER
}


// Render Frame
void Application::renderFrame(Scenario& scenario) {
    renderer->clear();
    visualiser->drawWorld(scenario.getWorld(), *camera);
    renderer->present();
}