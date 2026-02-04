#include <iostream>
#include "maths/vector.h"

int main() {
	Vector a{ 5, 3 };
	Vector b{ -3, 1 };
	std::cout << "Addition (a + b): " << (a + b) << std::endl;
	std::cout << "Subtraction (a - b): " << (a - b) << std::endl;
	std::cout << "Scalar Multiplication: " << (a * 5) << std::endl;
	std::cout << "Dot Product: " << dot(a, b) << std::endl;
	std::cout << "Magnitude (a): " << magnitude(a) << std::endl;
	return 0;
}