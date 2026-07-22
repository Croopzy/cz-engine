#pragma once
#include "src/engine/physics/bodies/point_mass/PointMass.hpp"

class RigidBody {
private:
    PointMass linearState; // Composition

    // Rotational State (Properties Are Signed Scalar Values)
    float inertia{0.0f}; // Unit: kg m^2, Symbol: I, Analogous To: Linear Inertial Mass
    float netTorque{0.0f}; // Unit: Nm, Symbol: τ, Analogous To: Net Force
    float inverseInertia{0.0f}; // Unit: (kg m^2)^-1
    float orientation{0.0f}; // Unit: Radians, Symbol: θ, Analogous To: Linear Position
    float angularSpeed{0.0f}; // Unit: rad s^-1, Symbol: ω, Analogous To: Linear Velocity
    float angularAcceleration{0.0f}; // Unit: rad s^-2, Symbol: α, Analogous To: Linear Acceleration

};