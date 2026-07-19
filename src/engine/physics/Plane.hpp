#pragma once
#include "PhysicsConstants.hpp"
#include "Particle.hpp"
#include "src/engine/core/Visuals.hpp"

// Plane Collider Structure
struct PlaneCollider {
    BasicVisuals visuals;

    Vector normal; // Normal Vector To The Plane (Unit Vector)
    float offset; // Shortest Perpendicular Distance From Origin To Plane (Along Normal)
    bool collisions; // Toggle Collisions with Plane
    float restitution; // Elasticity (Perfectly Inelastic: 0.0, Perfectly Elastic: 1.0)
    float friction; // Coefficient of Friction (Smoothest: 0.0, Roughest: 1.0)

    PlaneCollider(const Vector& vecN = {0.0f, 1.0f}, float planeConstant = 0, bool toggle = true, float elasticity = 0.5f, float roughness = 0.5f) noexcept
    : normal(isZero(vecN) ? Vector(0.0f, 1.0f) : normalise(vecN)),
    offset(planeConstant),
    collisions(toggle),
    restitution(elasticity),
    friction(roughness) {}
};


// Apply Friction To Particle Interacting with Plane
inline void applyFriction(Particle& body, PlaneCollider& plane, float distance) {
    // EVENT: Body Interacts with Plane
    if ((distance < PhysicsConstants::GROUND_EPSILON) && (plane.friction > 0) && (plane.friction <= 1)) {
        Vector tangent = perpendicular(plane.normal); // Unit Vector Parallel To Plane
        float vTangent = dot(body.velocity, tangent); // Signed Speed Along Surface
        float frImpulse = vTangent * plane.friction; // Proportion of Tangential Speed Lost Due To Friction
        body.velocity -= (tangent * frImpulse); // Update Velocity of Body
    }
};

// Apply Restitution To Particle Interacting with Plane
inline void applyRestitution(Particle& body, PlaneCollider& plane, float distance) {
    // EVENT: Body Penetrates Plane
    if (distance <= 0.0) {
        float vNormal = dot(body.velocity, plane.normal); // Scalar Magnitude of (Component of) Body Velocity Acting Along Normal
        // Position Correction
        float constraintViolation = -distance; // (Penetration Depth = -distance)
        body.position += plane.normal * constraintViolation; // Teleport Body Out of Plane
        // Only Bounce IF Body Moving Into Plane
        if (vNormal < -PhysicsConstants::GROUND_EPSILON){ // Negative (Downward) Velocity Check
            float bounceFactor = 1.0f + plane.restitution; // Scalar Proportion of Velocity: Current Kinetic Energy + Bounce Energy
            float deltaVn = bounceFactor * vNormal; // Scalar Proportion * (Component of) Current Body Velocity Along Plane Normal
            body.velocity -= (plane.normal * deltaVn); // Reverse Body's Normal Velocity and Apply Restitution (Energy Loss Due to Bounce)
        } else { // Remove Small Normal Velocity When In Resting Contact
            body.velocity -= (plane.normal * vNormal);
        }
    }
};


inline void planeInteract(Particle& body, PlaneCollider& plane) {
    float distance = dot(plane.normal, body.position) - plane.offset; // Signed Shortest Distance Between Body and Plane (Along Plane's Normal Axis)
    if ((body.collisions == true) && (plane.collisions == true)) { // IF Body-Plane Interacts Enabled
        applyFriction(body, plane, distance);
        applyRestitution(body, plane, distance);
    }

};