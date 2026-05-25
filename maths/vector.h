#pragma once // -> Prevents Inclusion of Multiple Headers
#include <cmath>
#include <ostream>
#include "constants.h"


// STRUCTURES //

struct Vector {
	float x; // -> Floats Are Sufficient, Doubles May Be Overkill
	float y;
	
	// Constructor
	Vector(float inX = 0.0f, float inY = 0.0f): // Initialise Vector = (0, 0)
		x(inX), y(inY) {}
		
	// Vector Negation (Unary Minus)
	constexpr Vector operator-() const {
	 return { -x, -y };
	}
};


// OPERATIONS //

// Vector Addition
constexpr  Vector operator+(const Vector& vecA, const Vector& vecB) {
	return { (vecA.x + vecB.x), (vecA.y + vecB.y) };
};

// Vector Subtraction
constexpr  Vector operator-(const Vector& vecA, const Vector& vecB) {
	return { (vecA.x - vecB.x), (vecA.y - vecB.y) };
};

// Scalar Multiplication (Case: Vector * Scalar)
constexpr  Vector operator*(const Vector& vecA, float numB) {
	return { (vecA.x * numB), (vecA.y * numB) };
};

// Scalar Multiplication (Case: Scalar * Vector)
constexpr Vector operator*(float numB, const Vector& vecA) {
    return vecA * numB;
};

// Scalar Division
constexpr Vector operator/(const Vector& vector, float scalarValue) {
    return { vector.x / scalarValue, vector.y / scalarValue }; // Does Not Account For Division Singularity
}

// Dot Product (Scalar)
constexpr float dot(const Vector& vecA, const Vector& vecB) {
	return (vecA.x * vecB.x) + (vecA.y * vecB.y);
};

// Perpendicular Vector (90° Rotation)
constexpr Vector perpendicular(const Vector& vecA) {
    return { -vecA.y, vecA.x };
}

// Scalar Cross Product 
constexpr float cross(const Vector& vecA, const Vector& vecB) {
    return vecA.x * vecB.y - vecA.y * vecB.x;
}


// Scalar Magnitude
inline float magnitude(const Vector& vecA) {
	return std::sqrt(dot(vecA, vecA));
};

// Vector Normalisation (Unit Vector)
inline Vector normalise(const Vector& vecA) {
    float magnitudeA = magnitude(vecA); // Dependency: Scalar Magnitude Operation
    if (magnitudeA <= EPSILON) { // Catch Division by Zero
        return {0.0f, 0.0f};
    }
    return { vecA.x / magnitudeA, vecA.y / magnitudeA };
}

// Vector Output
inline std::ostream& operator<<(std::ostream & os, const Vector & vecA) {
	return os << "(" << vecA.x << ", " << vecA.y << ")";
};