#pragma once

// Spring Structure (Binary Force Connecting Two Particles)
struct Spring {
    // World Indices of Connected Particles
    int particleA;
    int particleB;
    // Spring Properties
    float naturalLength; // Unaltered Spring 'Length'
    float stiffness; // Resistance To Stretching or Compression
    float damping; // Resistance To Relative Motion

    // Spring Constructor
    Spring(int a, int b, float l, float k, float d)
        : particleA(a),
          particleB(b),
          naturalLength(l),
          stiffness(k),
          damping(d)
    {}
};