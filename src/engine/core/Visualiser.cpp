#include "Visualiser.hpp"

// Visualiser Constructor
Visualiser::Visualiser(Renderer& renderer)
    : renderer(renderer) {
    // World & Camera References Not Members: Supports Multiple Worlds & Multiple Cameras
}

/// World Draw Functions ///

void Visualiser::drawParticles(const World& world, const Camera& camera) {
    for (const Particle& body : world.particles) {
        if (body.visuals.toggle == true) {
            renderer.drawCircle(camera, body.position.x, body.position.y, body.extras.radius, body.extras.fill, SDL_Color{body.visuals.r, body.visuals.g, body.visuals.b, body.visuals.a});
        }
    }
}

void Visualiser::drawPlanes(const World& world, const Camera& camera) {
    for (const World::PlaneCollider& plane : world.planes) {
        if (plane.visuals.toggle  == true) {
            Vector planePoint = plane.normal * plane.offset;
            Vector tangent = perpendicular(plane.normal);
            float planeLength = 10000.0f; // Fixed Plane Length (Default -> Infinity)
            Vector startPoint = planePoint + (tangent * planeLength);
            Vector endPoint = planePoint - (tangent * planeLength);
            renderer.drawLine(camera, startPoint.x, startPoint.y, endPoint.x, endPoint.y, SDL_Color{plane.visuals.r, plane.visuals.g, plane.visuals.b, plane.visuals.a});
        }
    }
}

void Visualiser::drawWorld(const World& world, const Camera& camera) {
    drawParticles(world, camera);
    drawPlanes(world, camera);
}