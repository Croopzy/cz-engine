#include <iostream>
#include "test/test_utils.hpp"
#include "src/engine/core/Application.hpp"
#include "src/simulations/freefall/Freefall.hpp"
#include "src/simulations/projectile/Projectile.hpp"
#include "src/simulations/oscillator/Oscillator.hpp"

int main() {

    runEngineTests();

    Application demo;
    Freefall freefall(900);
    Projectile projectile(900);
    Oscillator oscillator(900);
    demo.run(oscillator, true); // Run Simulation With Visualiser

	return 0;
}