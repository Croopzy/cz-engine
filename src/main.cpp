#include <iostream>
#include "test/utilities/test_utils.hpp"
#include "src/Cryoze/core/engine/Engine.hpp"
#include "src/examples/freefall/Freefall.hpp"
#include "src/examples/projectile/Projectile.hpp"
#include "src/examples/oscillator/Oscillator.hpp"

int main() {

    runEngineTests();

    Engine demo;
    Freefall freefall(900);
    Projectile projectile(900);
    Oscillator oscillator(900);
    demo.run(oscillator, true); // Run Simulation With Visualiser

	return 0;
}