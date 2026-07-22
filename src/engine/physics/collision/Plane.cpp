#include "Plane.hpp"

// Constructor
Plane::Plane(const Vector& vecN, float planeConstant, bool toggle, float elasticity, float roughness) noexcept // Uses Intitialiser List To Set World Parameters
    : normal(isZero(vecN) ? Vector(0.0f, 1.0f) : normalise(vecN)),
    offset(planeConstant),
    collisions(toggle),
    restitution(elasticity),
    friction(roughness)
{}


// Get Signed Shortest Distance Between Point & Plane
float Plane::signedDistance(const Vector& point), Plane& plane) const { return dot(normal, point) - offset; }


// Apply Friction To Particle Interacting with Plane
void applyFriction(Particle& body, Plane& plane, float distance) {
    // EVENT: Body Interacts with Plane
    if ((distance < 0.0f) && (plane.friction > 0) && (plane.friction <= 1)) {
        Vector tangent = perpendicular(plane.normal); // Unit Vector Parallel To Plane
        float vTangent = dot(body.velocity, tangent); // Signed Speed Along Surface
        float frImpulse = vTangent * plane.friction; // Proportion of Tangential Speed Lost Due To Friction
        body.velocity -= (tangent * frImpulse); // Update Velocity of Body
    }
};

// Apply Restitution To Particle Interacting with Plane
void applyRestitution(Particle& body, Plane& plane, float distance, float restEpsilon) {
    // EVENT: Body Penetrates Plane
    if (distance <= 0.0f) {
        float vNormal = dot(body.velocity, plane.normal); // Scalar Magnitude of (Component of) Body Velocity Acting Along Normal
        // Position Correction
        float constraintViolation = -distance; // (Penetration Depth = -distance)
        body.position += plane.normal * constraintViolation; // Teleport Body Out of Plane
        // Only Bounce IF Body Moving Into Plane
        if (vNormal < -restEpsilon){ // Negative (Downward) Velocity Check
            float bounceFactor = 1.0f + plane.restitution; // Scalar Proportion of Velocity: Current Kinetic Energy + Bounce Energy
            float deltaVn = bounceFactor * vNormal; // Scalar Proportion * (Component of) Current Body Velocity Along Plane Normal
            body.velocity -= (plane.normal * deltaVn); // Reverse Body's Normal Velocity and Apply Restitution (Energy Loss Due to Bounce)
        } else { // Remove Small Normal Velocity When In Resting Contact
            body.velocity -= (plane.normal * vNormal);
        }
    }
};


// Handle Interaction Between Particle & Plane
void planeInteract(Particle& body, Plane& plane, float dt) {
    float distance = dot(plane.normal, body.position) - plane.offset; // Signed Shortest Distance Between Body and Plane (Along Plane's Normal Axis)
    if ((body.collisions == true) && (plane.collisions == true)) { // IF Body-Plane Interacts Enabled
        applyFriction(body, plane, distance);
        float restEpsilon = magnitude(body.acceleration) * dt * PhysicsConstants::CONTACT_EPSILON_FACTOR; // Change in Speed Per Step (Frame) Due to Net Force, Scaled Up with Safety Margin  
        applyRestitution(body, plane, distance, restEpsilon);
    }
}
