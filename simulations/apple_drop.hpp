#include <iostream>
#include "engine/physics/world.hpp"

void runAppleDrop() {

    // Create Earth Simulation
    World earth;
    std::cout << "World Simulation Created: Earth\n"
    << "Gravity: " << earth.gravity;
    
    // Spawn Apple (Modelled As Particle)
    Particle& apple = earth.addParticle(0.1f); // Create Apple with Mass = 0.1kg in Earth Simulation
    std::cout << "Particle Model Created: Apple"
    << "\nMass: " << apple.mass << "kg";
    
    // Set Apple Initial Height
    int inHeight;
    std::cout << "Enter Height: ";
    std::cin >> inHeight;
    apple.position = {0.0f, inHeight};

    // Simulation Loop
    const int steps = 625; // 10 Seconds
	for (int i = 0; i < steps; ++i) {
        earth.step(0.016f); // Simulate Earth, dt = 0.016s
        // Ground Contact
        if (apple.y <= MathsConstants::EPSILON) {
            bool contact = True;
            std::cout << "GROUND REACHED"
            << "\nTime: " << i << "s"
            << "\Velocity: " << apple.velocity << "m/s";
        }
	}

	return 0;
}