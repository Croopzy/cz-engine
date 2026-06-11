#pragma once

#include "src/engine/maths/vector.hpp"

struct Camera {
    vector position;
    float viewportW; // Defines Width (px) of Draw Area
	float viewportH; // Defines Height (px) of Draw Area
};