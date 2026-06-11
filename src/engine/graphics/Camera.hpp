#pragma once

#include "src/engine/maths/vector.hpp"

struct Camera {
    vector position;
	float zoom; // Scale Factor (PPM, Pixels Per Metre)
	float viewportW; // Defines Width (px) of Draw Area
	float viewportH; // Defines Height (px) of Draw Area
};