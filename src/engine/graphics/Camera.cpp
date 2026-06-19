#include "Camera.hpp"

namespace CameraSpace {

/// Screen Projection Functions ///

Vector vecP(const float x, const float y)
{
    Vector vecPosition(x, y);
    return (vecPosition);
}

Vector worldToView(const Camera& camera, const Vector& worldPosition)
{
    Vector relativePosition = worldPosition - camera.position; // Translate Position Vector
    relativePosition.y = -relativePosition.y; // Invert Y-Position (SDL Flips Y)
    return (relativePosition * camera.zoom); // Scale Position Vector By Zoom
}

Vector viewToScreen(const Camera& camera, const Vector& viewPosition)
{
    // Move Camera To Middle of Screen
    float cameraX = camera.viewportWidth * 0.5f;
    float cameraY = camera.viewportHeight * 0.5f;
    Vector screenPosition(cameraX, cameraY);
    return(screenPosition);
}

Vector worldToScreen(const Camera& camera, const Vector& worldPosition)
{
    Vector viewPosition = worldToView(camera, worldPosition);
    Vector screenPosition = viewToScreen(camera, viewPosition);
    return (screenPosition);
}

Vector screenP(const Camera& camera, const float x, const float y)
{
    Vector vecPosition = vecP(x, y);
    return (worldToScreen(camera, vecPosition));
}


/// Camera Adjustment Functions ///

void zoom(Camera& camera, float deltaZoom)
{
    camera.zoom += deltaZoom; // Update Zoom

    if (camera.zoom < 0.1f) camera.zoom = 0.1f; // Clamp To Prevent Negative Or Zero Zoom
}

void follow(Camera& camera, const Vector& target, float stiffness)
{
    camera.position += (target - camera.position) * stiffness; // Update Camera Position Fractionally Toward Target (Scaled By Stiffness)
}

}