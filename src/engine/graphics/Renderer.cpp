#include "Renderer.hpp"

// Renderer Constructor
Renderer::Renderer(Window& window, Camera& camera)
    : window(window),
    camera(camera)
{
    renderer = SDL_CreateRenderer(window.getSDLWindow(), nullptr);
}

// Renderer Destructor
Renderer::~Renderer() { SDL_DestroyRenderer(renderer); }

// Reset Back Buffer (Empty Canvas)
void Renderer::clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}


// Displays Back Buffer Contents on Front Buffer (Screen)
void Renderer::present() { SDL_RenderPresent(renderer); }


/// Draw Functions ///

void Renderer::drawPoint(const Camera& camera, float x, float y, SDL_Color colour) {
    Vector vecPosition = CameraSpace::screenProjection(camera, x, y);
    SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
    SDL_RenderPoint(renderer, (int) vecPosition.x, (int) vecPosition.y);
}

void Renderer::drawLine(const Camera& camera, float x1, float y1, float x2, float y2, SDL_Color colour) {
    Vector vecPos1 = CameraSpace::screenProjection(camera, x1, y1);
    Vector vecPos2 = CameraSpace::screenProjection(camera, x2, y2);
    SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
    SDL_RenderLine(renderer, (int) vecPos1.x, (int) vecPos1.y, (int) vecPos2.x, (int) vecPos2.y);
}


/// World Draw Functions///
void Renderer::drawParticles(const World& world, const Camera& camera) {
    for (const Particle& body : world.particles) {
        Renderer::drawPoint(camera, body.position.x, body.position.y, SDL_Color{255, 255, 255, 255});
    }
}

void Renderer::drawPlanes(const World& world, const Camera& camera) {
    for (const World::PlaneCollider& plane : world.planes) {
        Vector planePoint = plane.normal * plane.offset;
        Vector tangent = perpendicular(plane.normal);
        float planeLength = 10000.0f; // Fixed Plane Length (Default -> Infinity)
        Vector startPoint = planePoint + (tangent * planeLength);
        Vector endPoint = planePoint - (tangent * planeLength);
        Renderer::drawLine(camera, startPoint.x, startPoint.y, endPoint.x, endPoint.y, SDL_Color{255, 255, 255, 255});
    }
}

void Renderer::drawWorld(const World& world, const Camera& camera) {
    Renderer::drawParticles(world, camera);
    Renderer::drawPlanes(world, camera);
}