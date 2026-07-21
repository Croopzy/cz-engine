#include <iostream>
#include "World.hpp"

// Constructor
World::World(const std::string& inName, const Vector& inGravity) noexcept // Uses Intitialiser List To Set World Parameters
    : name(inName),
    gravity(inGravity)
{}

void World::printInfo(const bool listParticles) noexcept {
    std::cout << "\nWorld: " << World::name << "\n"
    << "- Gravity = " << World::gravity << "ms^-2";
    if (listParticles) {
        std::cout << "\n- Particles:";
        for (Particle& body : particles) {
            std::cout << "\n  --> " << body.name << " (" << "Mass = " << body.getMass() << "kg, " << "Position = " << body.position << " )";
        }
    }
    std::cout << "}\n";
}


void World::accumulateForces() {
        for (Particle& body : particles) {
        body.clearForces(); // Reset Forces For Next Frame
        body.applyForce(gravity * body.getMass()); // Apply World Gravity (W = m * g)
    }
    for (Spring& spring : springs) {
        spring.applyForce(particles); // Apply Spring Constraints (F = -kx)
    }
}

// Step Simulation
void World::step(float dt) noexcept {
    
    // Update Resultant Force
    accumulateForces();
        
    // Velocity Verlet Integration: Update Particle Position
    for (Particle& body : particles) {
        body.integratePosition(dt);
    }

    // Update Resultant Force
    accumulateForces();

    // Velocity Verlet Integration: Update Particle Velocity
    for (Particle& body : particles) {
        body.integrateVelocity(dt);
    }

    // Collision Detection (Between Particles and Planes) & Impulse Resolution
    for (Particle& body : particles) {
        for (Plane& plane : planes) {
            planeInteract(body, plane, dt);
        }
    }
    
    stepN++;
}
