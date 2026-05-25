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

constexpr  Vector operator*(const Vector& vecA, float numB) { // Scalar Multiplication (Case I)
	return { (vecA.x * numB), (vecA.y * numB) };
};

constexpr Vector operator*(float numB, const Vector& vecA) { // Scalar Multiplication (Case II)
    return vecA * numB;
};

constexpr float dot(const Vector& vecA, const Vector& vecB) { // Dot Product (Scalar)
	return (vecA.x * vecB.x) + (vecA.y * vecB.y);
};

inline float magnitude(const Vector& vecA) { // Scalar Magnitude
	return std::sqrt(dot(vecA, vecA));
};

inline std::ostream& operator<<(std::ostream & os, const Vector & v) { // Vector Output
	return os << "(" << v.x << ", " << v.y << ")";
};