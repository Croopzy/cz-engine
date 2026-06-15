#include <iostream>
#include "test_utils.hpp"

// Text Markdown (Colour)
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"


namespace tests::detail {
void runTestGroup(const std::string& groupName, const std::vector<TestCase>& tests, const bool showCases) {

    std::cout << "\nUNIT TESTS INITIALISED: " << groupName;

    // Test Loop
    int numPassed = 0;
    if (showCases) std::cout << "\n\n";
    for (auto& test : tests) {
        bool pass = test.fn(); // Run Test Case
        if (pass) numPassed++; // Count Successful Tests
        if (showCases) {
            std::cout << test.name << ": " << (pass ? (GREEN "PASS") : (RED "FAIL")) << RESET << "\n"; // Output Status (Per Test, Colour-Coded)
        }
    }
    if (!showCases) std::cout << "\n";
    
    // Test Group Summary
    std::cout << "\n" << "[" << groupName << "] " << "UNIT TESTS SUMMARY:" << "\n"
    << "- " << GREEN << "Passed: " << RESET << numPassed << "\n"
    << "- " << RED << "Failed: " << RESET << (tests.size() - numPassed) << "\n\n\n";

} // End runTestGroup() Function
} // End tests::detail Namespace