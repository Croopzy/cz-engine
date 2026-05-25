#include <iostream>
#include "maths/vector.hpp"
#include "maths/geometry.hpp
// #include "particle.hpp"


int main() {
	Vector a{ 5, 3 };
	Vector b{ -3, 1 };
	float c(5.0f);
	std::cout << "Addition (a + b): " << (a + b) << std::endl;
	std::cout << "Subtraction (a - b): " << (a - b) << std::endl;
	std::cout << "Scalar Multiplication (a * c): " << (a * c) << std::endl;
	std::cout << "Scalar Multiplication (a * c): " << (a * c) << std::endl;
	std::cout << "Scalar Division (a / c): " << (a * c) << std::endl;
	std::cout << "Dot Product (a • b): " << dot(a, b) << std::endl;
	std::cout << "Magnitude (|a|): " << magnitude(a) << std::endl;
	std::cout << "Unary Negation (-a): " -a << std::endl;
	return 0;
}
