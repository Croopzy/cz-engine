#include <iostream>
#include <vector>
#include <string>
#include "test/utilities/test_utils.hpp"
#include "src/Cryoze/core/engine/Engine.hpp"   
#include "src/Cryoze/algorithms/merge_sort.hpp" 
#include "src/examples/freefall/Freefall.hpp"
#include "src/examples/projectile/Projectile.hpp"
#include "src/examples/oscillator/Oscillator.hpp"

int main() {

    runEngineTests();

    Engine demo;

    std::vector<std::string> names = {"Freefall", "Projectile", "Oscillator"}; // Update Manually
    mergeSort<std::string>(names, 0, static_cast<int>(names.size()) - 1);

    std::cout << "Available Simulations:\n";
    for (size_t i = 0; i < names.size(); ++i) {
        std::cout << "  " << (i + 1) << ": " << names[i] << "\n";
    }

    std::cout << "\nYour Selection: ";
    size_t selection;
    std::cin >> selection;
    std::cout << "\n\n";

    if ((selection < 1) || (selection > names.size())) {
        std::cout << "Invalid Selection.\n";
        return 1; // Indicates Failed Input
    }

    const std::string& selected = names[selection - 1];

    Freefall freefall(900);
    Projectile projectile(900);
    Oscillator oscillator(900);

    if (selected == "Freefall") demo.run(freefall, true);
    else if (selected == "Projectile") demo.run(projectile, true);
    else if (selected == "Oscillator") demo.run(oscillator, true);

	return 0;
}