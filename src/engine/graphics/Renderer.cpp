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


void Renderer::drawCircle(const Camera& camera, float centreX, float centreY, float inRadius, bool fillEnabled, SDL_Color colour) { // Bresenham Circle Algorithm (AKA Midpoint Circle Algorithm)
    int radius = (int)inRadius; // Casting Radius To Integer Type

    // Current Position in First Octant (Top of Circle)
    int x = 0;
    int y = radius;

    // Evaluation of f(x, y) At Midpoint, Tracked Incrementally
    int mpCircleF = 3 - (radius * 2); // Dervied From Implicit Circle Equation: f(x, y) = x^2 + y^2 - r^2

    // Draw Eight Symmetric Points Around Circle
    auto plotPoints = [&](int offsetX, int offsetY) { // Capture All Variables From Surrounding Scope By Reference Using [&]
        drawPoint(camera, (centreX + offsetX), (centreY + offsetY), colour);
        drawPoint(camera, (centreX + offsetX), (centreY - offsetY), colour);
        drawPoint(camera, (centreX - offsetX), (centreY + offsetY), colour);
        drawPoint(camera, (centreX - offsetX), (centreY - offsetY), colour);
        drawPoint(camera, (centreX + offsetY), (centreY + offsetX), colour);
        drawPoint(camera, (centreX + offsetY), (centreY - offsetX), colour);
        drawPoint(camera, (centreX - offsetY), (centreY + offsetX), colour);
        drawPoint(camera, (centreX - offsetY), (centreY - offsetX), colour);
    };

    // Draw Four Lines Between Symmetric Points Around Circle
    auto plotLines = [&](int offsetX, int offsetY) { // Capture All Variables From Surrounding Scope By Reference Using [&]
        // Horizontal Span Using (x, y)
        float leftX  = centreX - offsetX;
        float rightX = centreX + offsetX;
        float topY   = centreY + offsetY;
        float bottomY = centreY - offsetY;
        // Horizontal Span Swapped (y, x)
        float swapLeftX  = centreX - offsetY;
        float swapRightX = centreX + offsetY;
        float swapTopY   = centreY + offsetX;
        float swapBottomY = centreY - offsetX;
        // Draw Lines
        drawLine(camera, leftX, topY, rightX, topY, colour);
        drawLine(camera, leftX, bottomY, rightX, bottomY, colour);
        drawLine(camera, swapLeftX, swapTopY, swapRightX, swapTopY, colour);
        drawLine(camera, swapLeftX, swapBottomY, swapRightX, swapBottomY, colour);
    };

    // Walk From Top of Circle To 45° Diagonal
    while (y >= x) { // Continue Until Reaching 45° Diagonal
        if (fillEnabled) {plotLines(x, y); }
        else { plotPoints(x, y); }
        x++; // Always Move Right (By One Pixel)
        if (mpCircleF > 0) {// True Curve Below Midpoint (Midpoint Positioned Outside of Circle)
            y--; // Move Down (By One Pixel)
            mpCircleF += (4 * (x - y)) + 10;
        }
        else { // Midpoint Positioned Inside OR On Circle
            mpCircleF += (4 * x) + 6; // Stay Level
        }
    }

}


/// World Draw Functions///
void Renderer::drawParticles(const World& world, const Camera& camera) {
    for (const Particle& body : world.particles) {
        Renderer::drawCircle(camera, body.position.x, body.position.y, 5.00f, true, SDL_Color{255, 255, 255, 255});
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