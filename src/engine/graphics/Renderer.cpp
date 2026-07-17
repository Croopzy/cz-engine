#include "Renderer.hpp"
#include <string>

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
    SDL_RenderPoint(renderer, (int) std::round(vecPosition.x), (int) std::round(vecPosition.y));
}

void Renderer::drawLine(const Camera& camera, float x1, float y1, float x2, float y2, SDL_Color colour) {
    Vector vecPos1 = CameraSpace::screenProjection(camera, x1, y1);
    Vector vecPos2 = CameraSpace::screenProjection(camera, x2, y2);
    SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
    SDL_RenderLine(renderer, (int) std::round(vecPos1.x), (int) std::round(vecPos1.y), (int) std::round(vecPos2.x), (int) std::round(vecPos2.y));
}


void Renderer::drawCircle(const Camera& camera, float inCentreX, float inCentreY, float inRadius, bool fillEnabled, SDL_Color colour) { // Bresenham Circle Algorithm (AKA Midpoint Circle Algorithm)
    int radius = (int)inRadius; // Casting Radius To Integer Type

    // Convert Centre Position To Pixels
    Vector centre(inCentreX, inCentreY); // World Position
    centre = CameraSpace::worldToScreen(camera, centre); // Screen Position

    int centreX = std::round(centre.x);
    int centreY = std::round(centre.y);

    // Current Position in First Octant (Top of Circle)
    int x = 0;
    int y = radius;

    // Evaluation of f(x, y) At Midpoint, Tracked Incrementally
    int decision = 1 - y; // Decision Value, Integer Approximation of p = 1.25 - r

    // Plot One Point (By Pixels)
    auto plotPoint = [&](int pointX, int pointY) { // Capture All Variables From Surrounding Scope By Reference Using [&]
        SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
        SDL_RenderPoint(renderer, pointX, pointY);
    };

    // Draw Eight Symmetric Points Around Circle
    auto plot8Points = [&](int offsetX, int offsetY) { // Capture All Variables From Surrounding Scope By Reference Using [&]
        plotPoint((centreX + offsetX), (centreY + offsetY));
        plotPoint((centreX + offsetX), (centreY - offsetY));
        plotPoint((centreX - offsetX), (centreY + offsetY));
        plotPoint((centreX - offsetX), (centreY - offsetY));
        plotPoint((centreX + offsetY), (centreY + offsetX));
        plotPoint((centreX + offsetY), (centreY - offsetX));
        plotPoint((centreX - offsetY), (centreY + offsetX));
        plotPoint((centreX - offsetY), (centreY - offsetX));
    };

    // Plot One Line (By Pixels)
    auto plotLine = [&](int point1X, int point1Y, int point2X, int point2Y) { // Capture All Variables From Surrounding Scope By Reference Using [&]
        SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
        SDL_RenderLine(renderer, point1X, point1Y, point2X, point2Y);
    };

    // Draw Four Lines Between Symmetric Points Around Circle
    auto plot4Lines = [&](int offsetX, int offsetY) { // Capture All Variables From Surrounding Scope By Reference Using [&]
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
        plotLine(leftX, topY, rightX, topY);
        plotLine(leftX, bottomY, rightX, bottomY);
        plotLine(swapLeftX, swapTopY, swapRightX, swapTopY);
        plotLine(swapLeftX, swapBottomY, swapRightX, swapBottomY);
    };

    // Walk From Top of Circle To 45° Diagonal
    while (y >= x) { // Continue Until Reaching 45° Diagonal
        if (fillEnabled) {plot4Lines(x, y); }
        else { plot8Points(x, y); }
        x++; // Always Move Right (By One Pixel)
        if (decision > 0) {// True Curve Below Midpoint (Midpoint Positioned Outside of Circle)
            y--; // Move Down (By One Pixel)
            decision += (4 * (x - y)) + 10;
        }
        else { // Midpoint Positioned Inside OR On Circle
            decision += (4 * x) + 6; // Stay Level
        }
    }

}