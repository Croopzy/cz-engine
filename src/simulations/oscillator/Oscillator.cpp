#include "Oscillator.hpp"

Oscillator::Oscillator(int steps)
    : Scenario(),
      earth(getWorld()),
      bob(-1)
{
    numSteps = steps;
}

void Oscillator::start() {

    // Initialisation Outputs
    std::cout << "SIMULATION INITIALISED: MASS-SPRING OSCILLATOR\n\n";

    std::cout << "World Simulation Created: " << earth.name << "\n"
    << "Gravity: " << earth.gravity.y << "ms^-2\n\n";

    // Input Bob Initial Mass
    float inMass;
    std::cout << "Enter Mass of Bob (kg): ";
    std::cin >> inMass;

    // Input String Length
    float springLength;
    std::cout << "Enter Length of Spring (m): ";
    std::cin >> springLength;
    
    // Input Bob Vertical Displacement
    float inOffset;
    std::cout << "Enter Vertical Displacement (m): ";
    std::cin >> inOffset;

    // Calculate Bob Position
    Vector bobOffset;
    bobOffset.y -= springLength;
    bobOffset.y += inOffset;

    // Spawn Anchor
    Oscillator::anchor = earth.addParticle(0, "Anchor", Vector(100, 100)); // Create (White) Anchor (of Infinite Mass)
    Particle& anchorTemp = earth.getParticle(anchor);
    std::cout << "\nParticle Model Created: Anchor"
    << "\n- Anchor Mass: " << "Infinite" << "\n\n"; 

    // Spawn Bob
    Oscillator::bob = earth.addParticle(inMass, "Bob", (anchorTemp.position + bobOffset)); // Create Bob (Mass = inMass) in Earth Simulation, Default: Infinite Mass
    Particle& bobTemp = earth.getParticle(bob);
    std::cout << "\nParticle Model Created: Bob"
    << "\n- Bob Mass: " << bobTemp.getMass() << "kg" << "\n\n";
    bobTemp.visuals.r = 255; bobTemp.visuals.g = 0; bobTemp.visuals.b = 0; bobTemp.visuals.a = 1;

    // Spawn Spring(Grey, Light Rod) Between Anchor & Bob
    int spring = earth.addSpring(anchor, bob, springLength, 300, 10);
    Spring& springTemp = earth.getSpring(spring);
    springTemp.visuals.r = 0; springTemp.visuals.g = 0; springTemp.visuals.b = 0; springTemp.visuals.a = 0.5f;

    // Display World Information
    std::cout << "Simulation Construction Successful";
    earth.printInfo(true);

    int trail = earth.addParticle(0, "Trail Point", Vector(earth.getParticle(bob).position.x, earth.getParticle(bob).position.y));
    Particle& trailTemp = earth.getParticle(trail);
    trailTemp.visuals.r = 50; trailTemp.visuals.g = 0; trailTemp.visuals.b = 250; trailTemp.visuals.a = 150;
    trailTemp.extraVisuals.radius = 1;

}


void Oscillator::poll() {

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


void Oscillator::end() {

    // Conclusion Output
    std::cout << "\n\nSimulation Concluded"
    << "\n- Time: " << (numSteps * dt) << "s"
    << "\n- Final Velocity: " << earth.getParticle(bob).velocity << "m/s";

    std::cout << "\n\n";
}