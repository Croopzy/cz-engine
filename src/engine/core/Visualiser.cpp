#include "Visualiser.hpp"

// Visualiser Constructor
Visualiser::Visualiser(Renderer& renderer)
    : renderer(renderer) {
    // World & Camera References Not Members: Supports Multiple Worlds & Multiple Cameras
}

/// World Draw Functions ///

bool Visualiser::planeCollision(const Particle& body, const World::PlaneCollider& plane, const Camera& camera) {
    float distance = dot(plane.normal, body.position) - plane.offset; // Signed Shortest Distance Between Centre and Plane (Along Plane's Normal Axis)
    // Event: Particle Visually Penetrates Plane (Due To False Radius)
    if (distance <= body.extraVisuals.radius) {
        Vector screenCentre = CameraSpace::worldToScreen(camera, body.position);
        Vector screenNormal = plane.normal * camera.zoom;
        screenNormal.y = -screenNormal.y; // SDL Flips Y-Axis
        screenNormal = normalise(screenNormal);
        Vector newScreenCentre = screenCentre + (screenNormal * body.extraVisuals.radius);
        Vector newWorldCentre = CameraSpace::screenToWorld(camera, newScreenCentre);
        renderer.drawCircle(camera, newWorldCentre.x, newWorldCentre.y, body.extraVisuals.radius, body.extraVisuals.fill, SDL_Color{body.visuals.r, body.visuals.g, body.visuals.b, body.visuals.a});
        return true;
    }
    return false;
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

void Visualiser::drawParticles(const World& world, const Camera& camera) {
    for (const Particle& body : world.particles) {
        // EVENT: Visualisation Disabled 
        if (body.visuals.toggle == false) {
            continue; // Discard Iteration
        }
        // Detect Plane Collisions, Render Adjusted Particles
        bool collision = false;
        for (const World::PlaneCollider& plane : world.planes) {
            if (planeCollision(body, plane, camera) == true) {
                collision = true;
                break;
            }
        }
        // Render Uncollided Particles
        if (!collision) {
            renderer.drawCircle(camera, body.position.x, body.position.y, body.extraVisuals.radius, body.extraVisuals.fill, SDL_Color{body.visuals.r, body.visuals.g, body.visuals.b, body.visuals.a});
        }
    }
}

void Visualiser::drawWorld(const World& world, const Camera& camera) {
    drawPlanes(world, camera);
    drawParticles(world, camera);
}