#include "Visualiser.hpp"

// Visualiser Constructor
Visualiser::Visualiser(Renderer& renderer)
    : renderer(renderer) {
    // World & Camera References Not Members: Supports Multiple Worlds & Multiple Cameras
}

/// World Draw Functions ///

bool Visualiser::planeCollision(const World& world, const Particle& body, const Plane& plane, const Camera& camera) {
    float distance = dot(plane.normal, body.position) - plane.offset; // Signed Shortest Distance Between Centre and Plane (Along Plane's Normal Axis)
    // Event: Particle Visually Penetrates Plane (Due To False Radius)
    if ((body.collisions == true) && (plane.collisions == true) && (distance < body.extraVisuals.radius)) { // Collisions Enabled & Radius Overlaps with Plane
        float constraintViolation = body.extraVisuals.radius - distance;
        Vector adjustedPosition = body.position + (plane.normal * constraintViolation);
        renderer.drawCircle(camera, adjustedPosition.x, adjustedPosition.y, body.extraVisuals.radius, body.extraVisuals.fill, SDL_Color{body.visuals.r, body.visuals.g, body.visuals.b, body.visuals.a});
        recordTrail(world, body, adjustedPosition);
        return true;
    }
    return false;
}

void Visualiser::drawPlanes(const World& world, const Camera& camera) {
    for (const Plane& plane : world.planes) {
        // EVENT: Visualisation Disabled 
        if (plane.visuals.toggle == false) { continue; } // Discard Iteration
        Vector planePoint = plane.normal * plane.offset;
        Vector tangent = perpendicular(plane.normal);
        float planeLength = 10000.0f; // Fixed Plane Length (Default -> Infinity)
        Vector startPoint = planePoint + (tangent * planeLength);
        Vector endPoint = planePoint - (tangent * planeLength);
        renderer.drawLine(camera, startPoint.x, startPoint.y, endPoint.x, endPoint.y, SDL_Color{plane.visuals.r, plane.visuals.g, plane.visuals.b, plane.visuals.a});
    }
}

void Visualiser::recordTrail(const World& world, const Particle& body, const Vector& position) {
        if (body.extraVisuals.trail && ((world.stepN == 0) || ((world.stepN % body.extraVisuals.stepT) == 0))) {
        size_t index = &body - &world.particles[0]; // Find Index of body Within world.particles
        trails[index].push_back(position); // Add Trail Point To Array for Current Particle
    }
}

void Visualiser::drawTrail(const World& world, const Particle& body, const Camera& camera) {
    size_t index = &body - &world.particles[0];
    for (const Vector& position : trails[index]) { // For Each Trail Point of Current Particle Get Position
        renderer.drawCircle(camera, position.x, position.y, 1, true, SDL_Color{50, 0, 250, 150});
    }
}

void Visualiser::drawParticles(const World& world, const Camera& camera) {
    for (const Particle& body : world.particles) {
        // EVENT: Visualisation Disabled 
        if (body.visuals.toggle == false) { continue; } // Discard Iteration
        // Detect Plane Collisions, Render Adjusted Particles
        bool collision = false;
        for (const Plane& plane : world.planes) {
            if (planeCollision(world, body, plane, camera) == true) { // Detect Plane Collision, Resolve Trail Point Relative To Plane
                collision = true;
                break;
            }
        }
        // Render Uncollided Particles
        if (!collision) {
            renderer.drawCircle(camera, body.position.x, body.position.y, body.extraVisuals.radius, body.extraVisuals.fill, SDL_Color{body.visuals.r, body.visuals.g, body.visuals.b, body.visuals.a});
            recordTrail(world, body, body.position);
        }
        drawTrail(world, body, camera);
    }
}

void Visualiser::drawSprings(const World& world, const Camera& camera) {
    for (const Spring& spring : world.springs) {
        // EVENT: Visualisation Disabled 
        if (spring.visuals.toggle == false) { continue; } // Discard Iteration
        const Particle& particleA = world.getParticle(spring.particleA);
        const Particle& particleB = world.getParticle(spring.particleB);
        renderer.drawLine(camera, particleA.position.x, particleA.position.y, particleB.position.x, particleB.position.y, SDL_Color{spring.visuals.r, spring.visuals.g, spring.visuals.b, spring.visuals.a});
        }
    }

void Visualiser::drawWorld(const World& world, const Camera& camera) {
    if (trails.size() < world.particles.size()) {
        trails.resize(world.particles.size());
    }
    drawPlanes(world, camera);
    drawParticles(world, camera);
    drawSprings(world, camera);
}