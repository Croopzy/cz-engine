#pragma once
#include "engine/maths/vector.hpp"

namespace PhysicsConstants { // Avoids polluting global namespace
    // World Gravity Settings (Acceleration Due To Gravity, Unit: ms^-2)
    inline constexpr Vector GRAVITY_EARTH = Vector(0.0f, -9.81f);
    inline constexpr float GROUND_EPSILON = 0.05f;
}