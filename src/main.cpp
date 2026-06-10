#include <iostream>
#include <SDL3/SDL.h>
#include "src/engine/graphics/Application.hpp"
#include "test/test_utils.hpp"
#include "src/simulations/scenarios.hpp"

int main() {

    runMathsTests(true);

    runFreefall();

    SDL_Init(SDL_INIT_VIDEO);
    Application app;
    app.run();
    SDL_Quit();

	return 0;
}