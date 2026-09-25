#include "Oscillator.hpp"

Oscillator::Oscillator(int steps)
    : Scenario(),
      earth( getWorld() )
{
    numSteps = steps;
    zoom = 10;
}

void Oscillator::start() {

    // Initialisation Outputs
    std::cout << "SIMULATION INITIALISED: " << scenarioName << "\n\n";

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
    Oscillator::anchor = earth.addParticle(0, "Anchor", Vector(camX, (camY + (360 / zoom)))); // Create (White) Anchor (of Infinite Mass)
    std::cout << "\nParticle Model Created: Anchor"
    << "\n- Anchor Mass: " << "Infinite" << "\n\n"; 

    // Spawn Bob
    Oscillator::bob = earth.addParticle(inMass, "Bob", (anchor->linear().position + bobOffset)); // Create Bob (Mass = inMass) in Earth Simulation, Default: Infinite Mass
    std::cout << "\nParticle Model Created: Bob"
    << "\n- Bob Mass: " << bob->linear().getMass() << "kg" << "\n\n";
    bob->linear().visuals.r = 255; bob->linear().visuals.g = 0; bob->linear().visuals.b = 0; bob->linear().visuals.a = 1;

    // Spawn Spring(Grey, Light Rod) Between Anchor & Bob
    SpringID spring = earth.addSpring(anchor.particleID(), bob.particleID(), springLength, 300, 10);
    Spring& springTemp = earth.getSpring(spring);
    springTemp.visuals.r = 105; springTemp.visuals.g = 105; springTemp.visuals.b = 105; springTemp.visuals.a = 0.75f;

    // Display World Information
    std::cout << "Simulation Construction Successful";
    earth.printInfo(true);

}


void Oscillator::poll() {

    // EVENT: Every Second
    if (stepID % 60 == 0) {
        std::cout << "\n\nCurrent Time: " << (stepID * dt) << "s" <<
        "\nCurrent Velocity: " << bob->linear().velocity << "m/s" <<
        "\nCurrent Height: " << bob->linear().position.y << "m" << "\n";
    }
}


void Oscillator::end() {

    // Conclusion Output
    std::cout << "\n\nSimulation Concluded"
    << "\n- Time: " << (numSteps * dt) << "s"
    << "\n- Final Velocity: " << bob->linear().velocity << "m/s";

    std::cout << "\n\n";
}