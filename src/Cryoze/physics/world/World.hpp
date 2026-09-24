#pragma once
#include <vector>
#include "src/Cryoze/physics/PhysicsConstants.hpp"
#include "src/Cryoze/physics/collision/Plane.hpp"
#include "src/Cryoze/physics/bodies/Particle.hpp"
#include "src/Cryoze/physics/constraints/Spring.hpp"
#include "src/Cryoze/core/Visuals.hpp"

// Enumerators Distinguish Indexes to Planes, Particles and Springs
enum class PlaneID : int {};
enum class ParticleID : int {};
enum class SpringID : int {};

// World Class: Contains the physics environment, its bodies and its rules
class World {
public:

    // World Constructor
    World(const std::string& inName = "Earth", // Default World: Earth
        const Vector& inGravity = PhysicsConstants::GRAVITY_EARTH
    ) noexcept;

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
    inline PlaneID addPlane(const Vector& vecN = {0.0f, 1.0f}, float planeConstant = 0, bool collisions = true, float elasticity = 0.3f, float roughness = 0.5f) { 
        planes.emplace_back(vecN, planeConstant, collisions, elasticity, roughness); // Constructor
        return static_cast<PlaneID>(planes.size() - 1);; // Returns Index of New Plane
    }

    // New World Particle
    inline ParticleID addParticle(float mass = 0.0f, std::string name = "DefaultParticle", Vector position = Vector(0.0f, 0.0f)) { 
        particles.emplace_back(mass, name, position); // Constructs Particle Directly Inside Particles Vector
        return static_cast<ParticleID>(particles.size() - 1); // Returns Index of New Particle
    }

    // New World Spring
    inline SpringID addSpring(int particleA, int particleB, float naturalLength, float stiffness, float damping) {
        springs.emplace_back(particleA, particleB, naturalLength, stiffness, damping); // Constructor
        return static_cast<SpringID>(springs.size() - 1); // Returns Index of New Spring
    }


    // Get World Plane
    inline Plane& getPlane(PlaneID id) {
        return planes.at(static_cast<size_t>(id));
    }

    // Get World Particle
    inline Particle& getParticle(ParticleID id) {
        return particles.at(static_cast<size_t>(id));
    }

    // Overload (const): Get World Particle
    inline const Particle& getParticle(ParticleID id) const {
        return particles.at(static_cast<size_t>(id));
    }

    // Get World Spring
    inline Spring& getSpring(SpringID id) {
        return springs.at(static_cast<size_t>(id));
    }


    // Step Function Declaration
    void step(float dt = (1.0f / 60.0f)) noexcept;
    int stepN = 0;

private:

    // Update Resultant Force
    void accumulateForces();
};
