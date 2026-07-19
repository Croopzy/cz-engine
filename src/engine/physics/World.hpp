#pragma once
#include <vector>
#include "PhysicsConstants.hpp"
#include "Plane.hpp"
#include "Particle.hpp"
#include "Spring.hpp"
#include "src/engine/core/Visuals.hpp"

// World Class: Contains the physics environment, its bodies and its rules
class World {
public:

    // Step Function Declaration
    void step(float dt = (1.0f / 60.0f)) noexcept;
    int stepN = 0;

    // World Constructor
    World(const std::string& inName = "Earth", // Default World: Earth
    const Vector& inGravity = PhysicsConstants::GRAVITY_EARTH) noexcept;

    // Output World Information
    void printInfo(const bool listParticles = false) noexcept;


    // World Name
    std::string name;

    // World Parameters
    Vector gravity;

    // World Plane Colliders
    std::vector<Plane> planes; // Collection of Planes in World

    // World Particles
    std::vector<Particle> particles; // Collection of Particles in World

    // World Springs
    std::vector<Spring> springs; // Collection of Springs in World


    // New World Plane Collider
    inline int addPlane(const Vector& vecN = {0.0f, 1.0f}, float planeConstant = 0, bool collisions = true, float elasticity = 0.3f, float roughness = 0.5f) { 
        planes.emplace_back(vecN, planeConstant, collisions, elasticity, roughness); // Constructor
        return (planes.size() - 1); // Returns Index of New Plane
    }

    // New World Particle
    inline int addParticle(float mass = 0.0f, std::string name = "DefaultParticle", Vector position = Vector(0.0f, 0.0f)) { 
        particles.emplace_back(mass, name, position); // Constructs Particle Directly Inside Particles Vector
        return (particles.size() - 1); // Returns Index of New Particle
    }

    // New World Spring
    inline int addSpring(int particleA, int particleB, float naturalLength, float stiffness, float damping) {
        springs.emplace_back(particleA, particleB, naturalLength, stiffness, damping); // Constructor
        return (springs.size() - 1); // Returns Index of New Spring
    }


    // Get World Plane
    inline Plane& getPlane(int index) {
        return planes[index];
    }

    // Get World Particle
    inline Particle& getParticle(int index) {
        return particles[index];
    }

    // Overload (const): Get World Particle
    inline const Particle& getParticle(int index) const {
    return particles[index];
    }

    // Get World Spring
    inline Spring& getSpring(int index) {
        return springs[index];
    }


    // Apply Spring Force
    void applySpringForce(const Spring& spring);

private:
    // Update Resultant Force
    void accumulateForces();
};
