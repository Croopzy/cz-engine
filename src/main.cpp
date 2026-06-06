#include <iostream>
#include "simulations/apple_drop.hpp"
#include "engine/algorithms/mergesort.hpp"

int main() {
    std::vector<int> arr1 = {1, 4, 5, 2, 3};
    mergeSort(arr1, 0, 4);
    for (int i = 0; i < 5; i++) {
        std::cout << arr1[i] << " ";
    }
    runAppleDrop();
	return 0;
}