#include "Renderer.hpp"

// Renderer Constructor
Renderer::Renderer(Window& window, Camera& camera)
    : window(window),
    camera(camera)
{
    renderer = SDL_CreateRenderer(window.getSDLWindow(), nullptr);
}

// Renderer Deconstructor
Renderer::~Renderer() { SDL_DestroyRenderer(renderer); }

// Reset Back Buffer (Empty Canvas)
void Renderer::clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}


// Displays Back Buffer Contents on Front Buffer (Screen)
void Renderer::present() { SDL_RenderPresent(renderer); }


/// Draw Functions ///

void Renderer::drawPoint(Camera& camera, float x, float y, SDL_Color colour) {
    Vector vecPosition = CameraSpace::screenP(camera, x, y);
    SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
    SDL_RenderPoint(renderer, vecPosition.x, vecPosition.y);
}

void Renderer::drawLine(Camera& camera, float x1, float y1, float x2, float y2, SDL_Color colour) {
    Vector vecPos1 = CameraSpace::screenP(camera, x1, y1);
    Vector vecPos2 = CameraSpace::screenP(camera, x2, y2);
    SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
    SDL_RenderLine(renderer, vecPos1.x, vecPos1.y, vecPos2.x, vecPos2.y);
}