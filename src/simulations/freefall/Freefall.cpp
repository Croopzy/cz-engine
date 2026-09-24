#include "Freefall.hpp"

Freefall::Freefall(int steps)
    : Scenario(),
      earth( getWorld() )
{
    numSteps = steps;
}


void Freefall::start() {

    // Initialisation Outputs
    std::cout << "SIMULATION INITIALISED: " << scenarioName << "\n\n";

    std::cout << "World Simulation Created: " << earth.name << "\n"
    << "Gravity: " << earth.gravity.y << "ms^-2\n\n";

    // Create Earth Surface (Ground Plane Collider)
    earth.addPlane();

    // Input Apple Initial Mass
    float inMass;
    std::cout << "Enter Apple Mass (kg): ";
    std::cin >> inMass;

    // Input Apple Initial Height
    float inHeight;
    std::cout << "Enter Apple Height (m): ";
    std::cin >> inHeight;

    // Configure Apple
    appleID = earth.addParticle(inMass, "Apple", Vector(0, inHeight));
    std::cout << "\nParticle Model Created: Apple"
    << "\n- Apple Mass: " << apple().getMass() << "kg"
    << "\n- Apple Initial Height: " << apple().position.y << "m" << "\n\n";

    // Create Additional Particles
    earth.addParticle(85, "Superman", Vector(50.0f, 200.0f));
    earth.addParticle(10, "Rock", Vector(100.0f, 400.0f));

    // Display World Information
    std::cout << "Simulation Construction Successful";
    earth.printInfo(true);
}


void Freefall::poll() {

    // EVENT: Every Two Seconds
    if (stepID % 120 == 0) {
        std::cout << "\n\nCurrent Time: " << (stepID * dt) << "s" <<
        "\nCurrent Velocity: " << apple().velocity.y << "m/s" <<
        "\nCurrent Height: " << apple().position.y << "m" << "\n";
    }

    // EVENT: Apple Hits Ground
    if (groundContact == false && apple().position.y <= 0.0f) {
        groundContact = true;
        std::cout << "\n\nGROUND REACHED (APPLE)"
        << "\n- Time: " << (stepID * dt) << "s" // stepCount * dt = Time
        << "\n- Velocity: " << apple().velocity.y << "m/s" << "\n";
    }
}


void Freefall::end() {
    
    // Conclusion Output
    std::cout << "\n\nSimulation Concluded"
    << "\n- Time: " << (numSteps * dt) << "s"
    << "\n- Final Velocity: " << apple().velocity.y << "m/s";

    // Additional Ouput (Event)
    if (!groundContact) { // Apple Does Not Intersect Ground During Simulation Time Interval
        std::cout << "\n- Final Height: " << apple().position.y << "m" << "\n\n";
    } else std::cout << "\n\n";
}
