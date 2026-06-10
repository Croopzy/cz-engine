#include "Window.hpp"

Window::Window(const char* title, int width, int height) {
    window = SDL_CreateWindow(title, width, height, SDL_WINDOW_RESIZABLE);
}

Window::~Window() {
    SDL_DestroyWindow(window);
}