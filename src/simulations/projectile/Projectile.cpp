#include "Projectile.hpp"

Projectile::Projectile(int steps)
    : Scenario(),
      earth( getWorld() ),
      apple(-1)
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
    PointMass& appleTemp = earth.getParticle(apple).linear();
    appleTemp.project(radians(inAngle), inSpeed);
    appleTemp.visuals.r = 10; appleTemp.visuals.g = 210; appleTemp.visuals.b = 25;
    earth.getParticle(apple).extraVisuals.trail = true;
    earth.getParticle(apple).extraVisuals.trailPeriod = 30;
    std::cout << "\nParticle Model Created: Apple"
    << "\n- Apple Mass: " << appleTemp.getMass() << "kg" << "\n\n"
    << "\n- Apple Velocity: " << appleTemp.velocity << "m/s" << "\n\n";

    // Display World Information
    std::cout << "Simulation Construction Successful";
    earth.printInfo(true);

}


void Projectile::poll() {

    PointMass& appleTemp = earth.getParticle(apple).linear();

    // EVENT: Every Second
    if (stepID % 60 == 0) {
        std::cout << "\n\nCurrent Time: " << (stepID * dt) << "s" <<
        "\nCurrent Velocity: " << appleTemp.velocity << "m/s" <<
        "\nCurrent Height: " << appleTemp.position.y << "m" << "\n";
    }

    // EVENT: Apple Hits Ground
    if (groundContact == false && appleTemp.position.y <= 0.0f) {
        groundContact = true;
        std::cout << "\n\nGROUND REACHED"
        << "\n- Time: " << (stepID * dt) << "s" // stepCount * dt = Time
        << "\n- Velocity: " << appleTemp.velocity << "m/s" << "\n";
    }
}


void Projectile::end() {

    // Conclusion Output
    std::cout << "\n\nSimulation Concluded"
    << "\n- Time: " << (numSteps * dt) << "s"
    << "\n- Final Velocity: " << earth.getParticle(apple).linear().velocity.y << "m/s";

    // Additional Ouput (Event)
    if (!groundContact) { // Apple Does Not Intersect Ground During Simulation Time Interval
        std::cout << "\n- Final Height: " << earth.getParticle(apple).linear().position.y << "m" << "\n\n";
    } else std::cout << "\n\n";
}