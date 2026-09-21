#include "Camera.hpp"

namespace CameraSpace {

/// Screen Projection Functions ///

Vector worldToView(const Camera& camera, const Vector& worldPosition)
{
    Vector relativeWorldPosition = worldPosition - camera.position; // Translate Position Vector
    return (relativeWorldPosition * camera.zoom); // Scale Position Vector By Zoom
}

Vector viewToScreen(const Camera& camera, const Vector& viewPosition)
{
    // Move Camera To Middle of Screen, Add Offset
    float screenX = (camera.viewportWidth * 0.5f) + viewPosition.x;
    float screenY = (camera.viewportHeight * 0.5f) - viewPosition.y; // Also Inverts Y-Position (Since SDL Flips Y)
    return(Vector(screenX, screenY));
}

Vector worldToScreen(const Camera& camera, const Vector& worldPosition)
{
    Vector viewPosition = worldToView(camera, worldPosition);
    Vector screenPosition = viewToScreen(camera, viewPosition);
    return (screenPosition);
}

Vector screenProjection(const Camera& camera, const float x, const float y)
{
    Vector worldPosition(x, y); // Unit: Metres
    return (worldToScreen(camera, worldPosition)); // Unit: Pixels
}

Vector screenToWorld(const Camera& camera, const Vector& screenPosition)
{
    // Reverse viewToScreen()
    float viewX = screenPosition.x - (camera.viewportWidth * 0.5f);
    float viewY = (camera.viewportHeight * 0.5f) - screenPosition.y; // Undo SDL Y-Flip

    // Reverse worldToView()
    Vector worldPosition(viewX / camera.zoom, viewY / camera.zoom);

    // Add Camera Position Back
    return worldPosition + camera.position;
}


/// Camera Adjustment Functions ///

float scaleLength(const Camera& camera, float worldLength) {
    return worldLength * camera.zoom;
}

void zoom(Camera& camera, float deltaZoom)
{
    camera.zoom += deltaZoom; // Update Zoom

    if (camera.zoom < 0.001f) camera.zoom = 0.001f; // Clamp To Prevent Negative Or Zero Zoom
}

void follow(Camera& camera, const Vector& target, float stiffness)
{
    camera.position += (target - camera.position) * stiffness; // Update Camera Position Fractionally Toward Target (Scaled By Stiffness)
}

}
