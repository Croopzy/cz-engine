#pragma once
#include "src/engine/maths/vector.hpp"


// Camera Structure
struct Camera {
	Vector position; // Centre Position
	float zoom; // Scale Factor (PPM, Pixels Per Metre)
	int viewportWidth; // Defines Width (px) of Draw Area
	int viewportHeight; // Defines Height (px) of Draw Area

	// Camera Constructor
	Camera(Vector inPosition, float inZoom, int inVpWidth, int inVpHeight)
		: position(inPosition), zoom(inZoom), viewportWidth(inVpWidth), viewportHeight(inVpHeight) {}
};



namespace CameraSpace {

/// Screen Projection Functions ///

// Convert Coordinates To Position Vector
Vector vecP(const float x, const float y);

// Transformation: World To Camera View (Intermediate Step)
Vector worldToView(const Camera& camera, const Vector& worldPosition);

// Transformation: Camera View To Screen (Intermediate Step)
Vector viewToScreen(const Camera& camera, const Vector& viewPosition);

// Full Projection: World To Screen
Vector worldToScreen(const Camera& camera, const Vector& worldPosition);

// Project Position Onto Screen
Vector screenP(const Camera& camera, const float x, const float y);


/// Camera Adjustment Functions ///

// Adjust Zoom (Pixels Per Metre)
void zoom(Camera& camera, float deltaZoom);

// Smooth Follow (Camera Chases Target)
void follow(Camera& camera, const Vector& target, float stiffness);

}