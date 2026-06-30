#include "Visualiser.hpp"

// Visualiser Constructor
Visualiser::Visualiser(Renderer& renderer)
    : renderer(renderer) {
    // World & Camera References Not Members: Supports Multiple Worlds & Multiple Cameras
}

/// World Draw Functions ///

void Visualiser::drawParticles(const World& world, const Camera& camera) {
    for (const Particle& body : world.particles) {
        renderer.drawCircle(camera, body.position.x, body.position.y, 10.00f, true, SDL_Color{255, 255, 255, 255});
    }
}

void Visualiser::drawPlanes(const World& world, const Camera& camera) {
    for (const World::PlaneCollider& plane : world.planes) {
        Vector planePoint = plane.normal * plane.offset;
        Vector tangent = perpendicular(plane.normal);
        float planeLength = 10000.0f; // Fixed Plane Length (Default -> Infinity)
        Vector startPoint = planePoint + (tangent * planeLength);
        Vector endPoint = planePoint - (tangent * planeLength);
        renderer.drawLine(camera, startPoint.x, startPoint.y, endPoint.x, endPoint.y, SDL_Color{255, 255, 255, 255});
    }
}

void Visualiser::drawWorld(const World& world, const Camera& camera) {
    drawParticles(world, camera);
    drawPlanes(world, camera);
}