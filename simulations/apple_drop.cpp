#include <iostream>
#include "apple_drop.hpp"
#include "engine/physics/world.hpp"

void runAppleDrop() {

    // Create Earth Simulation
    World earth;
    std::cout << "World Simulation Created: Earth\n"
    << "Gravity: " << earth.gravity << "\n";
    
    // Input Apple Initial Mass
    float inMass;
    std::cout << "Enter Mass (kg): ";
    std::cin >> inMass;

    // Input Apple Initial Height
    float inHeight;
    std::cout << "Enter Height: ";
    std::cin >> inHeight;

    // Spawn Apple (Modelled As Particle)
    Particle& apple = earth.addParticle(inMass); // Create Apple (Mass = inMass) in Earth Simulation
    apple.position = {0.0f, inHeight}; // Set Apple Height
    std::cout << "Particle Model Created: Apple"
    << "\nMass: " << apple.mass << "kg"
    << "\nInitial Height: " << apple.position.y << "kg";

    // Simulation Loop
    const int steps = 625; // 10 Seconds
    float endTime = 10.0f; // Unit: Seconds
    bool contact = false;
    for (int i = 0; i < steps; ++i) {
        earth.step(0.016f); // Simulate Earth, dt = 0.016s
        // Ground Contact
        if (apple.position.y <= MathsConstants::EPSILON) {
            contact = true;
            endTime = i;
            std::cout << "GROUND REACHED"
            << "\nTime: " << i << "s"
            << "\nVelocity: " << apple.velocity << "m/s";
            break; // Prevents Output Repetition
        }
    }

    // End of Simulation Message
    std::cout << "Simulation Concluded"
    << "\n Time: " << endTime << "s"
    << "\nFinal Velocity: " << apple.velocity << "m/s";

    if (!contact) {
        std::cout << "\nFinal Height: " << apple.position.y << "m";
    }

}