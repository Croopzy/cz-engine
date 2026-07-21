#pragma once
#include <vector> // Dynamic Array Type
#include <string>

// Tests Structure
struct TestCase {
    const char* name;
    bool (*fn)(); // Test Function Pointer
};

// Generic Test Harness Declaration
namespace tests::detail { // Hides Infastructure From Public API
	void runTestGroup(const std::string& groupName, const std::vector<TestCase>& tests, const bool showCases = false);
}

// Internal Test Harness Declarations
namespace tests::modules { // Hides Engine Tests From Public API
	void runMathsTests(bool showCases = false);
}

inline void runEngineTests(bool showCases = false) {
	tests::modules::runMathsTests(showCases);
}
