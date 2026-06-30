#include "projectile.hpp"

Projectile::Projectile(int steps) : Scenario() {
    this->numSteps = steps;
}


void Projectile::start() {

    // Initialisation Outputs
    std::cout << "SIMULATION INITIALISED: PROJECTILE MOTION\n\n";

    std::cout << "World Simulation Created: " << earth.name << "\n"
    << "Gravity: " << earth.gravity.y << "ms^-2\n\n";

    // Create Earth Surface (Ground Plane Collider)
    earth.addPlane();

    // Input Apple Initial Mass
    float inMass;
    std::cout << "Enter Apple Mass (kg): ";
    std::cin >> inMass;

    // Configure Apple
    earth.getParticle(apple).setMass(inMass);
    std::cout << "\nParticle Model Created: Apple"
    << "\n- Apple Mass: " << earth.getParticle(apple).getMass() << "kg" << "\n\n";
    earth.getParticle(apple).velocity = Vector(10.00f, 30.00f);

    // Display World Information
    std::cout << "Simulation Construction Successful";
    earth.printInfo(true);

    earth.addParticle(0, "Trail Point", Vector(earth.getParticle(apple).position.x, earth.getParticle(apple).position.y));
}


void Projectile::poll() {

    // EVENT: Every Two Seconds
    if (stepID % 120 == 0) {
        std::cout << "\n\nCurrent Time: " << (stepID * dt) << "s" <<
        "\nCurrent Velocity: " << earth.getParticle(apple).velocity << "m/s" <<
        "\nCurrent Height: " << earth.getParticle(apple).position.y << "m" << "\n";
    }

    // EVENT: Every Second
    if (stepID % 60 == 0) {
        earth.addParticle(0, "Trail Point", Vector(earth.getParticle(apple).position.x, earth.getParticle(apple).position.y));
    }

    // EVENT: Apple Hits Ground
    if (groundContact == false && earth.getParticle(apple).position.y <= 0.0f) {
        groundContact = true;
        std::cout << "\n\nGROUND REACHED"
        << "\n- Time: " << (stepID * dt) << "s" // stepCount * dt = Time
        << "\n- Velocity: " << earth.getParticle(apple).velocity << "m/s" << "\n";
    }
}


void Projectile::end() {

    // Conclusion Output
    std::cout << "\n\nSimulation Concluded"
    << "\n- Time: " << (numSteps * dt) << "s"
    << "\n- Final Velocity: " << earth.getParticle(apple).velocity.y << "m/s";

    // Additional Ouput (Event)
    if (!groundContact) { // Apple Does Not Intersect Ground During Simulation Time Interval
        std::cout << "\n- Final Height: " << earth.getParticle(apple).position.y << "m" << "\n\n";
    } else std::cout << "\n\n";
}