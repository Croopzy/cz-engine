#include <iostream>
#include "simulations/apple_drop.hpp"
#include "algorithms/mergesort.hpp"

int main() {
    int arr1[5] = {1, 4, 5, 2, 3};
    mergeSort(arr1, 0, 4);
    std::cout << arr1;
    runAppleDrop();
	return 0;
}