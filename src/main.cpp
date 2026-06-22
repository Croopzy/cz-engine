#include <iostream>
#include "test/test_utils.hpp"
#include "src/simulations/freefall/freefall.hpp"

int main() {

    runEngineTests();

    Freefall freefall;
    freefall.runScenario();

	return 0;
}