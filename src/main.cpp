#include <iostream>
#include "test/test_utils.hpp"
#include "src/simulations/freefall/freefall.hpp"

int main() {

    runEngineTests();

    Freefall::runScenario();

	return 0;
}