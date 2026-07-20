#pragma once
#include "PhysicsConstants.hpp"
#include "Particle.hpp"
#include "src/engine/core/Visuals.hpp"

// Plane Structure
struct Plane {
    BasicVisuals visuals;

    Vector normal; // Normal Vector To The Plane (Unit Vector)
    float offset; // Shortest Perpendicular Distance From Origin To Plane (Along Normal)
    bool collisions; // Toggle Collisions with Plane
    float restitution; // Elasticity (Perfectly Inelastic: 0.0, Perfectly Elastic: 1.0)
    float friction; // Coefficient of Friction (Smoothest: 0.0, Roughest: 1.0)

    // Plane Constructor
    Plane(const Vector& vecN = {0.0f, 1.0f},
        float planeConstant = 0,
        bool toggle = true,
        float elasticity = 0.5f,
        float roughness = 0.5f
    ) noexcept;

};

// Apply Friction To Particle Interacting with Plane
void applyFriction(Particle& body, Plane& plane, float distance);

// Apply Restitution To Particle Interacting with Plane
void applyRestitution(Particle& body, Plane& plane, float distance, float restEpsilon);

// Handle Interaction Between Particle & Plane
void planeInteract(Particle& body, Plane& plane, float dt);