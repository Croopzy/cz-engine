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
    float friction;

    PlaneCollider(const Vector& vecN = {0.0f, 1.0f}, float planeConstant = 0, bool toggle = true, float elasticity = 0.5f, float roughness = 0.1f) noexcept
    : normal(isZero(vecN) ? Vector(0.0f, 1.0f) : normalise(vecN)),
    offset(planeConstant),
    collisions(toggle),
    restitution(elasticity),
    friction(roughness) {}
};

void collide(Particle& body, PlaneCollider& plane) {
    float distance = dot(plane.normal, body.position) - plane.offset; // Signed Shortest Distance Between Body and Plane (Along Plane's Normal Axis)
    // Event: Body Penetrates Plane (With Collisions Enabled)
    if ((body.collisions == true) && (plane.collisions == true) && (distance <= 0.0f)) {
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
    // Apply Friction (Tangential Velocity Component, Along Plane Surface)
    if ((plane.friction > 0) && (plane.friction >= 1)) {
        std::ignore;
    }

}