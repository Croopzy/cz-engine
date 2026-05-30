#pragma once
#include "maths/vector.hpp"

// STRUCTURES //

struct Particle {
    Vector position; // Current Position (Unit: metres, m)
    Vector velocity; // Current Velocity (Unit: ms^-1)
    Vector acceleration; // Acceleration = netForce * inverseMass (Unit: ms^-2)

    float mass; // Mass (Unit: kilograms, kg)
    float inverseMass; // (mass^-1 = 0 when mass -> infinity)

    Vector netForce; // Resultant Force (Unit: Newtons)

    Particle(float inMass = 1.0f):
        position(0,0),
        velocity(0,0),
        acceleration(0,0), // TODO: Gravity Will Be Updated Per-Particle
        mass(inMass),
        netForce(0,0)
    {
        if (mass == 0.0f) // Infinite Mass
            inverseMass = 0.0f;
        else
            inverseMass = 1.0f / mass;
    }

};
