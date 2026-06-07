#include <iostream>
#include <SDL3/SDL.h>
#include "engine/core/Application.hpp"
#include "engine/algorithms/mergesort.hpp"
#include "simulations/apple_drop.hpp"
#include <chrono>
#include <thread>

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    Application app;

    std::vector<int> arr1 = {1, 4, 5, 2, 3};
    mergeSort(arr1, 0, 4, true);
    for (int i = 0; i < 5; i++) {
        std::cout << arr1[i] << "...\n";
        std::this_thread::sleep_until(std::chrono::high_resolution_clock::now() + std::chrono::seconds(1));
    } std::cout << "Initialising...\n\n";

    runAppleDrop();

    app.run();
    SDL_Quit();
	return 0;
}