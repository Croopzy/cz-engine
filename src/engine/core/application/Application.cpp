#include "Application.hpp"
#include <chrono>
#include <thread>

void Application::run(Scenario& scenario, bool visualiserEnabled) {
    bool visualiserActive = false;

    scenario.start();

    if (visualiserEnabled) {
        // Create Window
        window = std::make_unique<Window>("Cryoze Engine", DEFAULT_WIDTH, DEFAULT_HEIGHT);
        // Create Camera
        camera = std::make_unique<Camera>(Vector(scenario.camX, scenario.camY), scenario.zoom, DEFAULT_WIDTH, DEFAULT_HEIGHT);
        // Create Renderer
        renderer = std::make_unique<Renderer>(*window, *camera);
        // Create Visualiser
        visualiser = std::make_unique<Visualiser>(*renderer);
        // Change Flag
        visualiserActive = true;
        // Render Initial Frame
        renderFrame(scenario);
    }

    SDL_Event event;

    auto nextTick = std::chrono::high_resolution_clock::now();
    auto delay = std::chrono::duration<float>(scenario.dt);
    auto nativeDelay = std::chrono::duration_cast<std::chrono::high_resolution_clock::duration>(delay);
    
    for (int i = 0; i < scenario.numSteps; ++i) {

        if (visualiserEnabled) {
            while (SDL_PollEvent(&event)) { // Always Poll Events
                if (event.type == SDL_EVENT_QUIT) {
                    visualiserActive = false;
                } else if (event.type == SDL_EVENT_WINDOW_RESIZED) {
                    camera->viewportWidth = event.window.data1;
                    camera->viewportHeight = event.window.data2;
                }
            }
        }

        // Update Scenario
        scenario.poll(); // Handle Events
        scenario.step(); // Step Physics

        // Render Scenario
        if (visualiserActive) {
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
