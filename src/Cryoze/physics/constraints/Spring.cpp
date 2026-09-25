#include "Spring.hpp"

// Apply Spring Force on Connected Particles
void Spring::applyForce(std::vector<Particle>& particles) {
    // Refer To Both Particles By Index
	PointMass& bodyA = particles[static_cast<size_t>(particleA)].linear();
	PointMass& bodyB = particles[static_cast<size_t>(particleB)].linear();
    // Vector From A -> B
    Vector delta = bodyB.position - bodyA.position;
    float currentLength = magnitude(delta);
    if (currentLength == 0.0f) return; // Avoids Division by Zero
    Vector direction = normalise(delta); // normalise(delta) == delta / currentLength
    // (+ve extension = stretched), (-ve extension = compressed)
    float extension = currentLength - naturalLength;
    // Hooke's Law: F = -kxd
    Vector stiffnessForce = -stiffness * extension * direction;
    // Relative Velocity
    Vector relativeVelocity = bodyB.velocity - bodyA.velocity; // Velocity of B Relative to Velocity of A
    // Component of Relative Velocity Along Spring Axis (Signed Scalar)
    float vParallel = dot(relativeVelocity, direction); // Changes Extension Since Direction Parallel To Plane
    // Damping Force: F = -kpd
    Vector dampingForce = -damping * vParallel * direction;
    // Total Spring Force Vector (A -> B)
    Vector springForce = stiffnessForce + dampingForce;
    // Apply Equal & Opposite Forces
    bodyA.applyForce(-springForce); // A Pulled Towards B
    bodyB.applyForce(springForce); // B Pulled Towards A
};
