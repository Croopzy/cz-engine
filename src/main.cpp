#include <iostream>
#include "simulations/apple_drop.hpp"
#include "engine/algorithms/mergesort.hpp"
#include <chrono>
#include <thread>

int main() {
    std::vector<int> arr1 = {1, 4, 5, 2, 3};
    mergeSort(arr1, 0, 4, true);
    for (int i = 0; i < 5; i++) {
        std::cout << arr1[i] << "...\n";
        std::this_thread::sleep_until(std::chrono::high_resolution_clock::now() + std::chrono::seconds(1));
    } std::cout << "Initialising...\n\n";

    runAppleDrop();
	return 0;
}