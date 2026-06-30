#include <iostream>
#include "test/test_utils.hpp"
#include "src/engine/core/Application.hpp"
#include "src/simulations/freefall/Freefall.hpp"
#include "src/simulations/projectile/Projectile.hpp"

int main() {

    runEngineTests();

    Application demo;
    Freefall freefall(900);
    Projectile projectile(900);
    demo.run(projectile, true); // Run Projectile Motion Simulation With Visualiser

	return 0;
}