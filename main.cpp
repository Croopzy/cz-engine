#include <iostream>
#include "physics/world.hpp"

int main() {

    World earth; // Create Simulation of Earth
    std::cout << "World Created: Earth\n"
    << "Gravity: " << earth.gravity;
    
    Particle apple(0.1f); // Apple with Mass 0.1kg
    apple.position = {0.0f, 10.0f} // Apple Begins Ten Metres High
    std::cout << "Particle Created: apple"
    << "\nMass: " << apple.mass
    << "\nVertical Position: " << apple.y << "m";

	for (int i = 0; i < 5; ++i) {
        // ...
	}

	return 0;
}
