#include "Projectile.hpp"

Projectile::Projectile(int steps)
    : Scenario(),
      earth( getWorld() )
{
    numSteps = steps;
}

void Projectile::start() {

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

    // Input Apple Initial Velocity (By Magnitude and Direction)
    float inAngle;
    std::cout << "Enter Projection Angle (Degrees): ";
    std::cin >> inAngle;
    float inSpeed;
    std::cout << "Enter Initial Speed (m/s): ";
    std::cin >> inSpeed;

    // Spawn Apple
    Projectile::apple = earth.addParticle(inMass, "Apple", Vector(0.0f, 0.0f)); // Create Apple (Mass = inMass) in Earth Simulation, Default: Infinite Mass
    apple->linear().project(radians(inAngle), inSpeed);
    apple->linear().visuals.r = 10; apple->linear().visuals.g = 210; apple->linear().visuals.b = 25; // TODO: Bring Linear Out of Accessor -> Whole Object Accessible
    apple->extraVisuals.trail = true;
    apple->extraVisuals.trailPeriod = 30;
    std::cout << "\nParticle Model Created: Apple"
    << "\n- Apple Mass: " << apple->linear().getMass() << "kg" << "\n\n"
    << "\n- Apple Velocity: " << apple->linear().velocity << "m/s" << "\n\n";

    // Display World Information
    std::cout << "Simulation Construction Successful";
    earth.printInfo(true);

}


void Projectile::poll() {

    // EVENT: Every Second
    if (stepID % 60 == 0) {
        std::cout << "\n\nCurrent Time: " << (stepID * dt) << "s" <<
        "\nCurrent Velocity: " << apple->linear().velocity << "m/s" <<
        "\nCurrent Height: " << apple->linear().position.y << "m" << "\n";
    }

    // EVENT: Apple Hits Ground
    if (groundContact == false && apple->linear().position.y <= 0.0f) {
        groundContact = true;
        std::cout << "\n\nGROUND REACHED"
        << "\n- Time: " << (stepID * dt) << "s" // stepCount * dt = Time
        << "\n- Velocity: " << apple->linear().velocity << "m/s" << "\n";
    }
}


void Projectile::end() {

    // Conclusion Output
    std::cout << "\n\nSimulation Concluded"
    << "\n- Time: " << (numSteps * dt) << "s"
    << "\n- Final Velocity: " << apple->linear().velocity.y << "m/s";

    // Additional Ouput (Event)
    if (!groundContact) { // Apple Does Not Intersect Ground During Simulation Time Interval
        std::cout << "\n- Final Height: " << apple->linear().position.y << "m" << "\n\n";
    } else std::cout << "\n\n";
}