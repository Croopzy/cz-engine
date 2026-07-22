#pragma once
#include "src/engine/physics/PhysicsConstants.hpp"
#include "Particle.hpp"
#include "src/engine/core/Visuals.hpp"

// Plane Structure
struct Plane {
public:
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
        float elasticity = 0.3f,
        float roughness = 0.5f
    ) noexcept;

    // Get Signed Shortest Distance Between Point & Plane
    float signedDistance(Vector point), Plane& plane);


};

// Apply Friction To Particle Interacting with Plane
void applyFriction(Particle& body, Plane& plane, float distance);

// Apply Restitution To Particle Interacting with Plane
void applyRestitution(Particle& body, Plane& plane, float distance, float restEpsilon);

// Handle Interaction Between Particle & Plane
void planeInteract(Particle& body, Plane& plane, float dt);
