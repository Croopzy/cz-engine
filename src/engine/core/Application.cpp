#include "Application.hpp"
#include <chrono>
#include <thread>


Application::Application()
    : window("Cryoze Engine", DEFAULT_WIDTH, DEFAULT_HEIGHT),
    camera(Vector(0, 0), 1.0f, DEFAULT_WIDTH, DEFAULT_HEIGHT),
    renderer(window, camera) {
    }


void Application::run(World& world) {
    bool active = true;
    SDL_Event event;

    auto previousTime = std::chrono::high_resolution_clock::now();
    float timeAccumulator = 0.0f;

    while (active) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) active = false;
        }

        // Frame Timing
        auto timeNow = std::chrono::high_resolution_clock::now();
        float frameTime = std::chrono::duration<float>(timeNow - previousTime).count();
        previousTime = timeNow;
        timeAccumulator += frameTime;

        // Step Physics
        while (timeAccumulator >= FIXED_DT)
        {
            world.step(FIXED_DT);
            timeAccumulator -= FIXED_DT;
        }

        // Render Frame
        renderer.clear();
        renderer.drawWorld(world, camera);
        renderer.present();
    }
}