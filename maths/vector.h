#pragma once // -> Prevents Inclusion of Multiple Headers
#include <cmath>


// STRUCTURES //

struct Vector {
	float x; // -> Floats Are Sufficient, Doubles May Be Overkill
	float y;
	Vector(float x_ = 0.0f, float y_ = 0.0f) : x(x_), y(y_) {}
};


// OPERATIONS //

inline  Vector operator+(const Vector& a, const Vector& b) { // Vector Addition
	return { (a.x + b.x), (a.y + b.y) };
};

inline  Vector operator-(const Vector& a, const Vector& b) { // Vector Subtraction
	return { (a.x - b.x), (a.y - b.y) };
};

inline  Vector operator*(const Vector& a, float b) { // Scalar Multiplication
	return { (a.x * b), (a.y * b) };
};

inline float dot(const Vector& a, const Vector& b) { // Dot Product (Scalar)
	return (a.x * b.x) + (a.y * b.y);
};

inline float magnitude(const Vector& v) { // Scalar Magnitude
	return std::sqrt(dot(v, v));
};

inline std::ostream& operator<<(std::ostream & os, const Vector & v) { // Vector Output
	return os << "(" << v.x << ", " << v.y << ")";
};