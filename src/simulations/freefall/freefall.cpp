#include "Freefall.hpp"

FreefallScenario::FreefallScenario(int steps) : Scenario() {
    this->numSteps = steps;
}


void FreefallScenario::start() {

    // Initialisation Outputs
    std::cout << "SIMULATION INITIALISED: FREEFALL\n\n";

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

    // Configure Apple
    apple.setMass(inMass);
    apple.position = {0.0f, inHeight}; // Set Apple Height
    std::cout << "\nParticle Model Created: Apple"
    << "\n- Apple Mass: " << apple.getMass() << "kg"
    << "\n- Apple Initial Height: " << apple.position.y << "m" << "\n\n";

    // Create Earth Surface (Ground Plane Collider)
    earth.addPlane();

    // Display World Information
    std::cout << "Simulation Construction Successful";
    earth.printInfo(true);

}


void FreefallScenario::poll() {

    // EVENT: Every Two Seconds
    if (stepID % 120 == 0) {
        std::cout << "\n\nCurrent Time: " << (stepID * dt) << "s" <<
        "\nCurrent Velocity: " << apple.velocity.y << "m/s" <<
        "\nCurrent Height: " << apple.position.y << "m" << "\n";
    }

    // EVENT: Apple Hits Ground
    if (groundContact == false && apple.position.y <= 0.0f) {
        groundContact = true;
        std::cout << "\n\nGROUND REACHED"
        << "\n- Time: " << (stepID * dt) << "s" // stepCount * dt = Time
        << "\n- Velocity: " << apple.velocity.y << "m/s" << "\n";
    }
}


void FreefallScenario::end() {

    // Conclusion Output
    std::cout << "\n\nSimulation Concluded"
    << "\n- Time: " << (numSteps * dt) << "s"
    << "\n- Final Velocity: " << apple.velocity.y << "m/s";

    // Additional Ouput (Event)
    if (!groundContact) { // Apple Does Not Intersect Ground During Simulation Time Interval
        std::cout << "\n- Final Height: " << apple.position.y << "m" << "\n\n";
    } else std::cout << "\n\n";
}