#pragma once
#include "src/Cryoze/maths/Vector.hpp"

namespace PhysicsConstants { // Avoids polluting global namespace
	// Fixed Timestep
	inline constexpr float FIXED_DT = 1.0f / 60.0f; // 60 FPS
    // World Gravity Settings (Acceleration Due To Gravity, Unit: ms^-2)
    inline constexpr Vector GRAVITY_EARTH = Vector(0.0f, -9.81f);
	// Other Configurables
    inline constexpr float CONTACT_EPSILON_FACTOR = 1.5f; // Theoretical Minimum = 100%, Safety Margin = 50%
}