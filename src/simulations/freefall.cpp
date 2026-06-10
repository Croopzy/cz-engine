#include <iostream>
#include "scenarios.hpp"
#include "src/engine/physics/world.hpp"
#include <chrono>
#include <thread>

void runFreefall() {
    
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
    std::cout << "\n\nWorld Simulation Created: " << earth.name << "\n"
    << "Gravity: " << earth.gravity.y << "ms^-2\n";

    // Spawn Apple (Modelled As Particle)
    Particle& apple = earth.addParticle(inMass); // Create Apple (Mass = inMass) in Earth Simulation
    apple.position = {0.0f, inHeight}; // Set Apple Height
    std::cout << "\nParticle Model Created: Apple"
    << "\n- Apple Mass: " << apple.mass << "kg"
    << "\n- Apple Initial Height: " << apple.position.y << "m" << "\n\n";

    // Add Earth Surface (Ground Plane Collider)
    earth.addPlane(); // Uses Default Plane Parameters

    // Display World Information
    std::cout << "Simulation Construction Successful";
    earth.printInfo(true);

    // Simulation Loop
    const int steps = 625; // 10 Seconds
    const float dt = 0.016; // Timestep, Unit: Seconds
    bool contact = false;
    for (int i = 0; i < steps; ++i) { // i = stepCount
        auto start = std::chrono::high_resolution_clock::now();
        earth.step(0.016f); // Simulate Earth, dt = 0.016s
        if (i % 125 == 0) { // Every Two Seconds
            std::cout << "\n\nCurrent Time: " << (i * dt) << "s" <<
            "\nCurrent Velocity: " << apple.velocity.y << "m/s" <<
            "\nCurrent Height: " << apple.position.y << "m" << "\n";
        }
        std::this_thread::sleep_until(start + std::chrono::milliseconds(16));
        // Ground Contact
        if (contact == false && apple.position.y <= 0.0f) {
            contact = true;
            std::cout << "\n\nGROUND REACHED"
            << "\n- Time: " << (i * dt) << "s" // stepCount * dt = Time
            << "\n- Velocity: " << apple.velocity.y << "m/s" << "\n";
        }
    }

    // End of Simulation Message
    std::cout << "\n\nSimulation Concluded"
    << "\n- Time: " << (steps * dt) << "s"
    << "\n- Final Velocity: " << apple.velocity.y << "m/s";

    if (!contact) {
        std::cout << "\n- Final Height: " << apple.position.y << "m" << "\n\n";
    } else std::cout << "\n\n";

}