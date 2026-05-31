#include <iostream>
#include "apple_drop.hpp"
#include "engine/physics/world.hpp"

void runAppleDrop() {
    
    // Input Apple Initial Mass
    float inMass;
    std::cout << "Enter Apple Mass (kg): ";
    std::cin >> inMass;

    // Input Apple Initial Height
    float inHeight;
    std::cout << "Enter Apple Height (m): ";
    std::cin >> inHeight;

    // Create Earth Simulation
    World earth;
    std::cout << "World Simulation Created: Earth"
    << "\n- World Gravity: " << earth.gravity.y << "ms^-2" << "\n\n";

    // Spawn Apple (Modelled As Particle)
    Particle& apple = earth.addParticle(inMass); // Create Apple (Mass = inMass) in Earth Simulation
    apple.position = {0.0f, inHeight}; // Set Apple Height
    std::cout << "\nParticle Model Created: Apple"
    << "\n- Apple Mass: " << apple.mass << "kg"
    << "\n- Apple Initial Height: " << apple.position.y << "m" << "\n\n";

    // Simulation Loop
    const int steps = 625; // 10 Seconds
    float endTime = 10.0f; // Unit: Seconds
    bool contact = false;
    for (int i = 0; i < steps; ++i) { // i = stepCount
        earth.step(0.016f); // Simulate Earth, dt = 0.016s
        // Ground Contact
        if (apple.position.y <= MathsConstants::EPSILON) {
            contact = true;
            endTime = i * 0.016f; // stepCount * dt = Time
            std::cout << "\nGROUND REACHED"
            << "\n- Time: " << endTime << "s"
            << "\n- Velocity: " << apple.velocity.y << "m/s" << "\n\n";
            break; // Prevents Output Repetition
        }
    }

    // End of Simulation Message
    std::cout << "\nSimulation Concluded"
    << "\n- Time: " << endTime << "s"
    << "\n- Final Velocity: " << apple.velocity.y << "m/s";

    if (!contact) {
        std::cout << "- Final Height: " << apple.position.y << "m" << "\n\n";
    }

}