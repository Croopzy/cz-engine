#include "Renderer.hpp"

Renderer::Renderer(Window& window) {
    renderer = SDL_CreateRenderer(window.get(), nullptr);
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(renderer);
}

void::Renderer::clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void::Renderer::present() {
    SDL_RenderPresent(renderer);
}


void::Renderer::drawPoint(int x, int y, SDL_Color colour) {
    SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
    SDL_RenderPoint(renderer, x, y);
}

void::Renderer::drawLine(int x1, int y1, int x2, int y2, SDL_Color colour) {
    SDL_SetRenderDrawColor(renderer, colour.r, colour.b, colour.g, colour.a);
    SDL_RenderLine(renderer, x1, y1, x2, y2);
}