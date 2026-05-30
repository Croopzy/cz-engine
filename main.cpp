#include <iostream>
#include "physics/world.hpp"

int main() {

    World earth; // Create Earth Simulation
    std::cout << "World Created: Earth\n"
    << "Gravity: " << earth.gravity;
    
    // Spawn Apple (Modelled As Particle)
    Particle& apple = earth.addParticle(0.1f); // Create Apple with Mass = 0.1kg in Earth Simulation (Modelled as Particle)
    apple.position = {0.0f, 10.0f}; // Apple Placed Ten Metres High
    std::cout << "Particle Created: Apple"
    << "\nMass: " << apple.mass << "kg"
    << "\Initial Height: " << apple.y << "m"; // Display Vertical Position of Apple
    
    // Simulate Five Seconds on Earth
	for (int i = 0; i < 5; ++i) {
        earth.step(1.0f); // dt = 1.0s
        std::cout << "Time: " << (i + 1) << "s"
        << "\nPosition: " << apple.position << "m"
        << "\Velocity: " << apple.velocity << "m/s"
	}

	return 0;
}
