#include <iostream>
#include "freefall.hpp"
#include <chrono>
#include <thread>

Freefall::Freefall() {
    steps = 600; // Selected Fixed Number of Steps
}

void Freefall::start() {
    
    std::cout << "SIMULATION INITIALISED: FREEFALL\n\n";

    // Begin Earth (Output Only)
    std::cout << "World Simulation Created: " << earth.name << "\n"
    << "Gravity: " << earth.gravity.y << "ms^-2\n\n";

    // Input Apple Initial Mass
    float inMass;
    std::cout << "Enter Apple Mass (kg): ";
    std::cin >> inMass;

    // Input Apple Initial Height
    float inHeight;
    std::cout << "Enter Apple Height (m): ";
    std::cin >> inHeight;

    // Spawn Apple (Modelled As Particle)
    apple.mass = inMass; // Set Apple Mass
    apple.position = {0.0f, inHeight}; // Set Apple Height
    std::cout << "\nParticle Model Created: Apple"
    << "\n- Apple Mass: " << apple.mass << "kg"
    << "\n- Apple Initial Height: " << apple.position.y << "m" << "\n\n";

    // Add Earth Surface (Ground Plane Collider)
    earth.addPlane(); // Uses Default Plane Parameters

    // Display World Information
    std::cout << "Simulation Construction Successful";
    earth.printInfo(true);

}

void Freefall::step(int i) {
    auto start = std::chrono::high_resolution_clock::now();
    earth.step(dt); // Simulate Earth
    if (i % 120 == 0) { // Every Two Seconds
        std::cout << "\n\nCurrent Time: " << (i * dt) << "s" <<
        "\nCurrent Velocity: " << apple.velocity.y << "m/s" <<
        "\nCurrent Height: " << apple.position.y << "m" << "\n";
    }

    std::this_thread::sleep_until(start + std::chrono::milliseconds(1000/60));
    // Ground Contact
    if (contact == false && apple.position.y <= 0.0f) {
        contact = true;
        std::cout << "\n\nGROUND REACHED"
        << "\n- Time: " << (i * dt) << "s" // stepCount * dt = Time
        << "\n- Velocity: " << apple.velocity.y << "m/s" << "\n";
    }
}

void Freefall::end() {
    // End of Simulation Message
    std::cout << "\n\nSimulation Concluded"
    << "\n- Time: " << (steps * dt) << "s"
    << "\n- Final Velocity: " << apple.velocity.y << "m/s";

    if (!contact) {
        std::cout << "\n- Final Height: " << apple.position.y << "m" << "\n\n";
    } else std::cout << "\n\n";

}

void Freefall::runScenario() {
    start();

    for (int i = 0; i < steps; ++i) { // i = stepCount
        step(i);
    }

    end();
}