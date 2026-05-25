#pragma once // -> Prevents Inclusion of Multiple Headers
#include <cmath>
#include <ostream>


// STRUCTURES //

struct Vector {
	float x; // -> Floats Are Sufficient, Doubles May Be Overkill
	float y;
	Vector(float inX = 0.0f, float inY = 0.0f) // Initialise Vector = (0, 0)
		: x(inX), y(inY) {}
};


// OPERATIONS //

constexpr  Vector operator+(const Vector& vecA, const Vector& vecB) { // Vector Addition
	return { (vecA.x + vecB.x), (vecA.y + vecB.y) };
};

constexpr  Vector operator-(const Vector& vecA, const Vector& vecB) { // Vector Subtraction
	return { (vecA.x - vecB.x), (vecA.y - vecB.y) };
};

constexpr Vector operator-(const Vector& vecA) { // Unary Minus (Vector)
    return { -vecA.x, -vecA.y };
}

constexpr  Vector operator*(const Vector& vecA, float numB) { // Scalar Multiplication (Case I)
	return { (vecA.x * numB), (vecA.y * numB) };
};

constexpr Vector operator*(float numB, const Vector& vecA) { // Scalar Multiplication (Case II)
    return vecA * numB;
};

constexpr float dot(const Vector& vecA, const Vector& vecB) { // Dot Product (Scalar)
	return (vecA.x * vecB.x) + (vecA.y * vecB.y);
};

constexpr Vector perpendicular(const Vector& vecA) { // Perpendicular Vector (Cross Product in 2D)
    return { -vecA.y, vecA.x };
}

inline float magnitude(const Vector& vecA) { // Scalar Magnitude
	return std::sqrt(dot(vecA, vecA));
};

inline Vector normalise(const Vector& vecA) { // Vector Normalisation
    float magnitudeA = magnitude(v); // Requires magnitude()
    if (magnitudeA == 0.0f) { // Catch Division by Zero
        return {0.0f, 0.0f};
    }
    return { vecA.x / magnitudeA, vecA.y / magnitudeA };
}

inline std::ostream& operator<<(std::ostream & os, const Vector & v) { // Vector Output
	return os << "(" << v.x << ", " << v.y << ")";
};