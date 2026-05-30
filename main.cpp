#include <iostream>
#include "physics/world.hpp"

int main() {

    World earth; // Create Earth Simulation
    std::cout << "World Created: Earth\n"
    << "Gravity: " << earth.gravity;
    
    // Spawn Apple (Modelled As Particle)
    Particle bodyA(0.1f); // Create Particle with Mass = 0.1kg
    bodyA.position = {0.0f, 10.0f}; // Particle Begins Ten Metres High
    earth.particles.push_back(bodyA); // Register Particle in Earth Simulation
    Particle& apple = earth.particles.back(); // Create Reference to Particle in World (apple)
    std::cout << "Particle Created: apple"
    << "\nMass: " << apple.mass << "kg"
    << "\Initial Height: " << apple.y << "m" // Display Vertical Position of Apple
    << "\Acceleration: " << apple.acceleration << "ms^-2"; // Display Acceleration of Apple

    // TO CHECK: Acceleration probably shows as zero here because a world step hasn't been carried out to apply gravity
    
    // Simulate Five Seconds on Earth
	for (int i = 0; i < 5; ++i) {
        earth.step(1.0f); // dt = 1.0s
        std::cout << "Time: " << (i + 1) << "s"
        << "\nPosition: " << apple.position << "m"
        << "\Velocity: " << apple.velocity << "m/s"
	}

	return 0;
}
