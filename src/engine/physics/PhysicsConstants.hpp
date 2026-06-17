#pragma once
#include "src/engine/maths/Vector.hpp"

namespace PhysicsConstants { // Avoids polluting global namespace
	// Fixed Timestep
	inline constexpr float FIXED_DT = 1.0f / 60.0fm // 60 FPS
    // World Gravity Settings (Acceleration Due To Gravity, Unit: ms^-2)
    inline constexpr Vector GRAVITY_EARTH = Vector(0.0f, -9.81f);
	// Other Configurables
    inline constexpr float GROUND_EPSILON = 0.05f;
}