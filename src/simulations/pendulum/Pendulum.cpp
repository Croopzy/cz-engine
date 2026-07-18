#include "Pendulum.hpp"

Pendulum::Pendulum(int steps)
    : Scenario(),
      earth(getWorld()),
      bob(-1)
{
    numSteps = steps;
}

void Pendulum::start() {

    // Initialisation Outputs
    std::cout << "SIMULATION INITIALISED: ELASTIC PENDULUM\n\n";

    std::cout << "World Simulation Created: " << earth.name << "\n"
    << "Gravity: " << earth.gravity.y << "ms^-2\n\n";

    // Create Earth Surface (Ground Plane Collider)
    // earth.addPlane({(0.0), (-200.0)});

    // Input Bob Initial Mass
    float inMass;
    std::cout << "Enter Mass of Bob (kg): ";
    std::cin >> inMass;

    // Input String Length
    float stringLength;
    std::cout << "Enter Length of Pendulum (m): ";
    std::cin >> stringLength;
    
    // Input Bob Angular Displacement
    float inTheta;
    std::cout << "Enter Angular Displacement (Degrees): ";
    std::cin >> inTheta;

    // Input Bob Initial Speed
    float inSpeed;
    std::cout << "Enter Initial Speed (m/s): ";
    std::cin >> inSpeed;

    // Spawn Pivot
    Pendulum::pivot = earth.addParticle(0, "Pivot", Vector(100, 100)); // Create (White) Pivot (of Infinite Mass)
    Particle& pivotTemp = earth.getParticle(pivot);
    std::cout << "\nParticle Model Created: Pivot"
    << "\n- Pivot Mass: " << "Infinite" << "\n\n"; 

    // Calculate Bob Position
    float theta = radians(inTheta);
    float bobX = pivotTemp.position.x + (sin(theta) * stringLength);
    float bobY = pivotTemp.position.y - (cos(theta) * stringLength);

    // Spawn Bob
    Pendulum::bob = earth.addParticle(inMass, "Bob", Vector(bobX, bobY)); // Create Bob (Mass = inMass) in Earth Simulation, Default: Infinite Mass
    Particle& bobTemp = earth.getParticle(bob);
    std::cout << "\nParticle Model Created: Bob"
    << "\n- Bob Mass: " << bobTemp.getMass() << "kg" << "\n\n"
    << "\n- Bob Velocity: " << bobTemp.velocity << "m/s" << "\n\n";
    bobTemp.visuals.r = 255; bobTemp.visuals.g = 0; bobTemp.visuals.b = 0; bobTemp.visuals.a = 1;

    // Spawn String (Light, Inextensible) Between Pivot & Bob
    earth.addSpring(pivot, bob, stringLength, -20.0f, 2.0f);

    // Display World Information
    std::cout << "Simulation Construction Successful";
    earth.printInfo(true);

    int trail = earth.addParticle(0, "Trail Point", Vector(earth.getParticle(bob).position.x, earth.getParticle(bob).position.y));
    Particle& trailTemp = earth.getParticle(trail);
    trailTemp.visuals.r = 50; trailTemp.visuals.g = 0; trailTemp.visuals.b = 250; trailTemp.visuals.a = 150;
    trailTemp.extraVisuals.radius = 1;

}


void Pendulum::poll() {

    // EVENT: Every Second
    if (stepID % 60 == 0) {
        std::cout << "\n\nCurrent Time: " << (stepID * dt) << "s" <<
        "\nCurrent Velocity: " << earth.getParticle(bob).velocity << "m/s" <<
        "\nCurrent Height: " << earth.getParticle(bob).position.y << "m" << "\n";

        int trail = earth.addParticle(0, "Trail Point", Vector(earth.getParticle(bob).position.x, earth.getParticle(bob).position.y));
        earth.getParticle(trail).visuals.r = 50;
        earth.getParticle(trail).visuals.g = 0;
        earth.getParticle(trail).visuals.b = 250;
        earth.getParticle(trail).visuals.a = 150;
        earth.getParticle(trail).extraVisuals.radius = 1;
    }
}


void Pendulum::end() {

    // Conclusion Output
    std::cout << "\n\nSimulation Concluded"
    << "\n- Time: " << (numSteps * dt) << "s"
    << "\n- Final Velocity: " << earth.getParticle(bob).velocity << "m/s";

    std::cout << "\n\n";
}