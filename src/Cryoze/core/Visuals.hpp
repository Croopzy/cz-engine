#pragma once
#include <cstdint>

struct BasicVisuals {
    // Colour (RGBA)
    uint8_t r = 255;
    uint8_t g = 255;
    uint8_t b = 255;
    uint8_t a = 255;

    // Presentation Flags
    bool toggle = true; // Toggle Object Visibility
};