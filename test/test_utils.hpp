#pragma once
#include <vector> // Dynamic Array Type

// Tests Structure
struct TestCase {
    const char* name;
    bool (*fn)(); // Test Function Pointer
};

// Generic Test Harness Declaration
void runTestGroup(const std::string& groupName, const std::vector<TestCase>& tests, const bool showCases);

// Test Harness Declarations
void runMathsTests(bool showCases);