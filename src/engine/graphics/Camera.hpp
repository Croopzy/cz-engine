#pragma once

#include "src/engine/maths/vector.hpp"

/// Camera Structure ///
struct Camera {
	Vector position; // Centre Position
	float zoom; // Scale Factor (PPM, Pixels Per Metre) -- TODO: REMOVE FROM RENDERER
	int viewportWidth; // Defines Width (px) of Draw Area
	int viewportHeight; // Defines Height (px) of Draw Area

	// Camera Constructor
	Camera(Vector inPosition, float inZoom, int inVpWidth, int inVpHeight)
		: position(inPosition), zoom(inZoom), viewportWidth(inVpWidth), viewportHeight(inVpHeight) {}
};


/// Transform Functions (API) ///

// ...