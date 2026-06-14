#include "Window.hpp"

Window::Window(const char* title, int w, int h)
    : width(w), height(h)
{
    window = SDL_CreateWindow(title, w, h, SDL_WINDOW_RESIZABLE);
}

Window::~Window() {
    SDL_DestroyWindow(window);
}

SDL_Window* Window::getSDLWindow() const {
    return window;
}

int Window::getWidth() const { return width; }
int Window::getHeight() const { return height; }

void Window::setSize(int newWidth, int newHeight) {
    width = newWidth;
    height = newHeight;
    SDL_SetWindowSize(window, width, height);
}

void Window::setWidth(int newWidth) {
    setSize(newWidth, height;
}

void Window::setHeight(int newHeight) {
    setSize(width, newHeight;
}