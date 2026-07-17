#include "projectile.hpp"

Projectile::Projectile(int steps)
    : Scenario(),
      earth(getWorld()),
      apple(-1)
{
    numSteps = steps;
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

    // Input Apple Initial Velocity (By Overall Magnitude and Direction)
    float inAngle;
    std::cout << "Enter Projection Angle (Degrees): ";
    std::cin >> inAngle;
    float inSpeed;
    std::cout << "Enter Initial Speed (m/s): ";
    std::cin >> inSpeed;

    // Spawn Apple
    Projectile::apple = earth.addParticle(inMass, "Apple", Vector(0.0f, 0.0f)); // Create Apple (Mass = inMass) in Earth Simulation, Default: Infinite Mass
    Particle& appleTemp = earth.getParticle(apple);
    appleTemp.project(radians(inAngle), inSpeed);
    std::cout << "\nParticle Model Created: Apple"
    << "\n- Apple Mass: " << appleTemp.getMass() << "kg" << "\n\n"
    << "\n- Apple Velocity: " << appleTemp.velocity << "m/s" << "\n\n";
    appleTemp.visuals.r = 10; appleTemp.visuals.g = 210; appleTemp.visuals.b = 25;

    // Display World Information
    std::cout << "Simulation Construction Successful";
    earth.printInfo(true);

    int trail = earth.addParticle(0, "Trail Point", Vector(earth.getParticle(apple).position.x, earth.getParticle(apple).position.y));
    Particle& trailTemp = earth.getParticle(trail);
    trailTemp.visuals.r = 50; trailTemp.visuals.g = 0; trailTemp.visuals.b = 250; trailTemp.visuals.a = 150;
    trailTemp.extraVisuals.radius = 1;

}


void Projectile::poll() {

    // EVENT: Every Second
    if (stepID % 60 == 0) {
        std::cout << "\n\nCurrent Time: " << (stepID * dt) << "s" <<
        "\nCurrent Velocity: " << earth.getParticle(apple).velocity << "m/s" <<
        "\nCurrent Height: " << earth.getParticle(apple).position.y << "m" << "\n";

        int trail = earth.addParticle(0, "Trail Point", Vector(earth.getParticle(apple).position.x, earth.getParticle(apple).position.y));
        earth.getParticle(trail).visuals.r = 50;
        earth.getParticle(trail).visuals.g = 0;
        earth.getParticle(trail).visuals.b = 250;
        earth.getParticle(trail).visuals.a = 150;
        earth.getParticle(trail).extraVisuals.radius = 1;
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
