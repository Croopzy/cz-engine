#include "Window.hpp"

// Window Constructor
Window::Window(const char* title, int w, int h)
    : width(w), height(h)
{
    window = SDL_CreateWindow(title, w, h, SDL_WINDOW_FULLSCREEN);
}

// Window Destructor
Window::~Window() { SDL_DestroyWindow(window); }

// Get Window Pointer
SDL_Window* Window::getSDLWindow() const { return window; }

// Get Window Dimensions
int Window::getWidth() const { return width; }
int Window::getHeight() const { return height; }

// Window Resize
void Window::setSize(int newWidth, int newHeight) {
    width = newWidth;
    height = newHeight;
    SDL_SetWindowSize(window, width, height);
}

// Window Width Adjustment
void Window::setWidth(int newWidth) {
    setSize(newWidth, height);
}

// Window Height Adjustment
void Window::setHeight(int newHeight) {
    setSize(width, newHeight);
}