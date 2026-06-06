#pragma once
#include <vector>
#include "particle.hpp"
#include "spring.hpp"

// World Class: Contains the physics environment, its bodies and its rules
class World {
public:

    // World Constructor
    World() noexcept;

    // Step Function Declaration
    void step(float dt) noexcept;

    // World Parameters
    Vector gravity;

    // World Particles
    std::vector<Particle> particles; // Collection of Particles in World

    // New World Particle
    inline Particle& addParticle(float mass) { 
        particles.emplace_back(mass); // Constructs Particle Directly Inside Particles Vector
        return particles.back(); // Returns Reference to New Particle
    }

    // World Springs
    std::vector<Spring> springs; // Collection of Springs in World

    // New World Spring
    inline void addSpring(int particleA, int particleB, float naturalLength, float stiffness, float damping) {
        springs.emplace_back(particleA, particleB, naturalLength, stiffness, damping); // Constructor
    }

    // Apply Spring Force
    void applySpringForce(const Spring& spring);

    // Plane Collider Structure
    struct PlaneCollider {
        Vector normal; // Normal Vector To The Plane (Unit Vector)
        float offset; // Shortest Perpendicular Distance From Origin To Plane (Along Normal)
        float restitution; // Elasticity (Perfectly Inelastic: 0.0, Perfectly Elastic: 1.0)

        PlaneCollider(const Vector& vecN, float planeConstant, float elasticity = 0.3f) noexcept
        : normal(normalise(vecN)), offset(planeConstant), restitution(elasticity) {}
    };

    // World Plane Colliders
    std::vector<PlaneCollider> planes; // Collection of Planes in World

};