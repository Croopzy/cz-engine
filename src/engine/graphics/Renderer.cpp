#include "Renderer.hpp"

Renderer::Renderer(Window& window)
    : window(window)
{
    renderer = SDL_CreateRenderer(window.getSDLWindow(), nullptr);
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(renderer);
}

void Renderer::clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Renderer::present() {
    SDL_RenderPresent(renderer);
}


/// Conversions: Metres -> Pixels ///

int Renderer::projectX(float metresX) const {
    return static_cast<int>(metresX * PPM); // Left To Right, Convert Metres To Pixels
}

int Renderer::projectY(float metresY) const {
    return window.getHeight() - static_cast<int>(metresY * PPM); // Top To Bottom (SDL3 Default) Inverted, Convert Metres To Pixels
}


/// Draw Functions ///

void Renderer::drawPoint(float x, float y, SDL_Color colour) {
    SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
    SDL_RenderPoint(renderer, projectX(x), projectY(y));
}

void Renderer::drawLine(float x1, float y1, float x2, float y2, SDL_Color colour) {
    SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
    SDL_RenderLine(renderer, projectX(x1), projectY(y1), projectX(x2), projectY(y2));
}