#include <iostream>
#include "maths/vector.hpp"
#include "maths/geometry.hpp"
// #include "particle.hpp"


int main() {
	// Example Values
	Vector a{ 5, 3 };
	Vector b{ -3, 1 };
	float c(5.0f);
	// Test Operations
	std::cout << "Addition (a + b): " << (a + b) << std::endl;
	std::cout << "Subtraction (a - b): " << (a - b) << std::endl;
	std::cout << "Scalar Multiplication (a * c): " << (a * c) << std::endl;
	std::cout << "Scalar Multiplication (c * a): " << (c * a) << std::endl;
	std::cout << "Scalar Division (a / c): " << (a * c) << std::endl;
	std::cout << "Addition Assignment (a += b): " << (a += b) << std::endl;
	std::cout << "Subtraction Assignment (a -= b): " << (a -= b) << std::endl;
	std::cout << "Scalar Multiplication Assignment (a *= c): " << (a *= c) << std::endl;
	std::cout << "Scalar Division Assignment (a /= c): " << (a /= c) << std::endl;
	std::cout << "Scalar Cross Product (a x b): " << cross(a, b) << std::endl;
	std::cout << "Dot Product (a • b): " << dot(a, b) << std::endl;
	std::cout << "Magnitude (|a|): " << magnitude(a) << std::endl;
	std::cout << "Vector Normalisatiom (â): " << normalise(a) << std::endl;
	std::cout << "Perpendicular Vector (⊥a): " << perpendicular(a) << std::endl;
	std::cout << "Unary Negation (-a): " -a << std::endl;
	std::cout << "Relative Angle (θ): " << angle(a, b) << std::endl;
	return 0;
}
