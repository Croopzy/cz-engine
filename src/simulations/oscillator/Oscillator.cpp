#include "Oscillator.hpp"

Oscillator::Oscillator(int steps)
    : Scenario(),
      earth(getWorld()),
      anchor(-1),
      bob(-1)
{
    numSteps = steps;
    zoom = 10;
}

void Oscillator::start() {

    // Initialisation Outputs
    std::cout << "SIMULATION INITIALISED: DAMPED HARMONIC MOTION\n\n";

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
    PointMass& anchorTemp = earth.getParticle(anchor).linear();
    std::cout << "\nParticle Model Created: Anchor"
    << "\n- Anchor Mass: " << "Infinite" << "\n\n"; 

    // Spawn Bob
    Oscillator::bob = earth.addParticle(inMass, "Bob", (anchorTemp.position + bobOffset)); // Create Bob (Mass = inMass) in Earth Simulation, Default: Infinite Mass
    PointMass& bobTemp = earth.getParticle(bob).linear();
    std::cout << "\nParticle Model Created: Bob"
    << "\n- Bob Mass: " << bobTemp.getMass() << "kg" << "\n\n";
    bobTemp.visuals.r = 255; bobTemp.visuals.g = 0; bobTemp.visuals.b = 0; bobTemp.visuals.a = 1;

    // Spawn Spring(Grey, Light Rod) Between Anchor & Bob
    int spring = earth.addSpring(anchor, bob, springLength, 300, 10);
    Spring& springTemp = earth.getSpring(spring);
    springTemp.visuals.r = 105; springTemp.visuals.g = 105; springTemp.visuals.b = 105; springTemp.visuals.a = 0.75f;

    // Display World Information
    std::cout << "Simulation Construction Successful";
    earth.printInfo(true);

}


void Oscillator::poll() {

    PointMass& bobTemp = earth.getParticle(bob).linear();

    // EVENT: Every Second
    if (stepID % 60 == 0) {
        std::cout << "\n\nCurrent Time: " << (stepID * dt) << "s" <<
        "\nCurrent Velocity: " << bobTemp.velocity << "m/s" <<
        "\nCurrent Height: " << bobTemp.position.y << "m" << "\n";
    }
}


void Oscillator::end() {

    // Conclusion Output
    std::cout << "\n\nSimulation Concluded"
    << "\n- Time: " << (numSteps * dt) << "s"
    << "\n- Final Velocity: " << earth.getParticle(bob).linear().velocity << "m/s";

    std::cout << "\n\n";
}
