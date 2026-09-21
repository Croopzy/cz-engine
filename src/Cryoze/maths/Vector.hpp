#pragma once // Prevents Inclusion of Multiple Headers
#include <cmath>
#include <ostream>
#include "MathsConstants.hpp"


/// STRUCTURES ///

struct Vector {
	float x; // -> Floats Are Sufficient, Doubles May Be Overkill
	float y;

	// Vector Methods //

	// Constructor
	constexpr Vector(float inX = 0.0f, float inY = 0.0f) noexcept: // Initialise Vector = (0, 0)
		x(inX), y(inY) {
	}

	// Unary Negation (Vector Negation): -vector
	[[nodiscard]] inline constexpr Vector operator-() const noexcept {
	 return { -x, -y };
	}
	
	// Addition Assignment: vectorA += vectorB
	inline constexpr Vector operator+=(const Vector& vecB) noexcept {
		x += vecB.x;
		y += vecB.y;
	 return *this;
	}
	
	// Subtraction Assignment: vectorA -= vectorB
	inline constexpr Vector operator-=(const Vector& vecB) noexcept {
		x -= vecB.x;
		y -= vecB.y;
	 return *this;
	}
	
	// Scalar Multiplication Assignment: vector *= scalar
	inline constexpr Vector operator*=(float numB) noexcept {
		x *= numB;
		y *= numB;
	 return *this;
	}
	
	// Scalar Divsion Assignment: vector /= scalar
	inline constexpr Vector operator/=(float numB) noexcept {
		if (std::fabs(numB) <= MathsConstants::EPSILON) return *this;
		x /= numB;
		y /= numB;
	 return *this;
	}
};


/// OPERATIONS ///

// Vector Initialisation by Angle (Measured in Radians From Horizontal) & Magnitude: vectorA.resolve(magnitude, angle)
[[nodiscard]] inline constexpr Vector resolve(float angle, float magnitude) noexcept {
	return { (std::cos(angle) * magnitude), (std::sin(angle) * magnitude) };
}

// Vector Addition: vectorA + vectorB
[[nodiscard]] inline Vector operator+(const Vector& vecA, const Vector& vecB) noexcept {
	return { (vecA.x + vecB.x), (vecA.y + vecB.y) };
}

// Vector Subtraction: vectorA - vectorB
[[nodiscard]] inline constexpr Vector operator-(const Vector& vecA, const Vector& vecB) noexcept {
	return { (vecA.x - vecB.x), (vecA.y - vecB.y) };
}

// Scalar Multiplication: vector * scalar
[[nodiscard]] inline constexpr Vector operator*(const Vector& vecA, float numB) noexcept {
	return { (vecA.x * numB), (vecA.y * numB) };
}

// Scalar Multiplication: scalar * vector
[[nodiscard]] inline constexpr Vector operator*(float numB, const Vector& vecA) noexcept {
    return vecA * numB;
}

// Scalar Division: vector / scalar
[[nodiscard]] inline constexpr Vector operator/(const Vector& vecA, float numB) noexcept {
    return { vecA.x / numB, vecA.y / numB }; // Does Not Account For Division Singularity
}

// Dot Product (Scalar): dot(vectorA, vectorB)
[[nodiscard]] constexpr float dot(const Vector& vecA, const Vector& vecB) noexcept {
	return (vecA.x * vecB.x) + (vecA.y * vecB.y);
}

// Scalar Cross Product: cross(vectorA, vectorB)
[[nodiscard]] constexpr float cross(const Vector& vecA, const Vector& vecB) noexcept {
    return (vecA.x * vecB.y) - (vecA.y * vecB.x);
}

// Scalar Magnitude: magnitude(vector)
[[nodiscard]] inline constexpr float magnitude(const Vector& vecA) noexcept {
	return std::sqrt(dot(vecA, vecA)); // Dependency: Dot Product
}

// Zero Vector Check: isZero(vector)
[[nodiscard]] constexpr bool isZero(const Vector& vecA, float epsilon = MathsConstants::EPSILON) noexcept{
	return ((vecA.x * vecA.x) + (vecA.y * vecA.y)) < (epsilon * epsilon); // Magnitude^2 < Epsilon^2 (No Use of sqrt: More Stabilise & Efficient)
}

// Vector Normalisation (Unit Vector): normalise(vector)
[[nodiscard]] inline Vector normalise(const Vector& vecA) noexcept {
    float magnitudeA = magnitude(vecA); // Dependency: Scalar Magnitude
    if (magnitudeA <= MathsConstants::EPSILON) { // Catch Division by Zero
        return {0.0f, 0.0f};
    }
    return { vecA.x / magnitudeA, vecA.y / magnitudeA };
}

// Perpendicular Vector (90° Rotation): perpendicular(vector)
[[nodiscard]] inline constexpr Vector perpendicular(const Vector& vecA) noexcept {
    return { -vecA.y, vecA.x };
}

// Vector Output
inline std::ostream& operator<<(std::ostream & os, const Vector & vecA) { // Operator Overload (<<)
	return os << "(" << vecA.x << ", " << vecA.y << ")";
}


/// GEOMETRIC FUNCTIONS ///

// Convert Degrees To Radians: radians(angle)
inline float radians(float inAngle) {
	return (inAngle * MathsConstants::PI / 180); // angle (radians) = angle (°) * (2π ⁄ 360) = angle (°) * (π / 180)
}

// Convert Radians To Degrees: degrees(angle)
inline float degrees(float inAngle) {
	return (inAngle * 180 / MathsConstants::PI); // angle (°) = angle (radians) * (360 / 2π) = angle (radians) * (180 / π)
}

// Unsigned Angle Between Two Vectors (Relative Angle, Unit: Radians): angle(vectorA, vectorB)
inline float angle(const Vector& vecA, const Vector& vecB) {
    float dotProduct = dot(vecA, vecB);
    float magnitudeProduct = magnitude(vecA) * magnitude(vecB);
    if (magnitudeProduct <= MathsConstants::EPSILON) return 0.0f; // Accounts For Division Singularity
    float cosine = dotProduct / magnitudeProduct;
    if (cosine > 1.0f) cosine = 1.0f; // Clamp To Valid Range (For Floating Point Drift)
    if (cosine < -1.0f) cosine = -1.0f;
    return std::acos(cosine); // Return Angle in Radians
}