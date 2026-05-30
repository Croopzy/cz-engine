#include <iostream>
#include "maths/vector.hpp"
#include "maths/geometry.hpp"
// #include "physics/particle.hpp"

int main() {

	Vector position(0.0f, 0.0f);
	Vector velocity(0.0f, 0.0f);

	for (int i = 0; i < 5; ++i) {
		std::cout << "Step: " << i << "\n"
		<< "Position: " << position <<  << "\n"
		<< "Velocity: " << velocity <<  << "\n";
	}

	return 0;
}
