#include <iostream>
#include "test/test_utils.hpp"
#include "src/engine/core/Application.hpp"
#include "src/simulations/freefall/freefall.hpp"
#include "src/simulations/projectile/projectile.hpp"

int main() {

    runEngineTests();

    Application demo;
    FreefallScenario freefall(900);
    ProjectileScenario projectile(900);
    demo.run(projectile, true);

	return 0;
}