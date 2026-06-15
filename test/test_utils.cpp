#include <iostream>
#include "test_utils.hpp"

// Text Markdown (Colour)
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"


void runTestGroup(const std::string& groupName, const std::vector<TestCase>& tests, const bool showCases) {

    std::cout << "\nUNIT TESTS: " << groupName << "\n";

    // Test Loop
    int numPassed = 0;
    for (auto& test : tests) {
        bool pass = test.fn(); // Run Test Case
        if (pass) numPassed++; // Count Successful Tests
        if (showCases) {
            std::cout << test.name << ": " << (pass ? (GREEN "PASS") : (RED "FAIL")) << RESET << "\n"; // Output Status (Per Test, Colour-Coded)
        }
    }
    
    // Test Group Summary
    std::cout << GREEN << "\nPassed: " << RESET << numPassed
    << RED << "\nFailed: " << RESET << (tests.size() - numPassed) << "\n\n";

}