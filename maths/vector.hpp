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
		
	// Unary Negation (Vector Negation): -vector
	constexpr Vector operator-() const {
	 return { -x, -y };
	}
	
	// Addition Assignment: vectorA += vectorB
	constexpr Vector operator+=(const Vector& vecB) {
		x += vecB.x;
		y += vecB.y;
	 return *this;
	}
	
	// Subtraction Assignment: vectorA -= vectorB
	constexpr Vector operator-=(const Vector& vecB) {
		x -= vecB.x;
		y -= vecB.y;
	 return *this;
	}
	
	// Scalar Multiplication Assignment: vector *= scalar
	constexpr Vector operator*=(float numB) {
		x *= numB;
		y *= numB;
	 return *this;
	}
	
	// Scalar Divsion Assignment: vector /= scalar
	constexpr Vector operator/=(float numB) {
		x /= numB; // Does Not Account For Division Singularity
		y /= numB;
	 return *this;
	}
};


// OPERATIONS //

// Vector Addition: vectorA + vectorB
constexpr  Vector operator+(const Vector& vecA, const Vector& vecB) {
	return { (vecA.x + vecB.x), (vecA.y + vecB.y) };
};

// Vector Subtraction: vectorA - vectorB
constexpr  Vector operator-(const Vector& vecA, const Vector& vecB) {
	return { (vecA.x - vecB.x), (vecA.y - vecB.y) };
};

// Scalar Multiplication: vector * scalar
constexpr  Vector operator*(const Vector& vecA, float numB) {
	return { (vecA.x * numB), (vecA.y * numB) };
};

// Scalar Multiplication: scalar * vector
constexpr Vector operator*(float numB, const Vector& vecA) {
    return vecA * numB;
};

// Scalar Division: vector / scalar
constexpr Vector operator/(const Vector& vecA, float numB) {
    return { vecA.x / numB, vecA.y / numB }; // Does Not Account For Division Singularity
}

// Dot Product (Scalar): dot(vectorA, vectorB)
constexpr float dot(const Vector& vecA, const Vector& vecB) {
	return (vecA.x * vecB.x) + (vecA.y * vecB.y);
};

// Perpendicular Vector (90° Rotation): perpendicular(vector)
constexpr Vector perpendicular(const Vector& vecA) {
    return { -vecA.y, vecA.x };
}

// Scalar Cross Product: cross(vectorA, vectorB)
constexpr float cross(const Vector& vecA, const Vector& vecB) {
    return vecA.x * vecB.y - vecA.y * vecB.x;
}

// Scalar Magnitude: magnitude(vector)
inline float magnitude(const Vector& vecA) {
	return std::sqrt(dot(vecA, vecA));
};

// Vector Normalisation (Unit Vector): normalise(vector)
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
