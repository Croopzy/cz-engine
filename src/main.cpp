#include <iostream>
#include "test/test_utils.hpp"
#include "src/engine/core/Application.hpp"
#include "src/simulations/freefall/freefall.hpp"

int main() {

    runEngineTests();

    Application demo;
    FreefallScenario freefall;
    demo.run(freefall);

	return 0;
}