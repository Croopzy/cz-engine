#include <iostream>
#include <vector> // dynamic array type
#include "maths/vector.hpp"
#include "maths/geometry.hpp"

// Vector Unit Tests
bool test_unary_negation() {
    Vector vecA(3.0f, 4.0f);
    Vector result = -vecA;
    return(result.x == -3.0f && result.y == -4.0f);
}
    
bool test_addition_assignment() {
    Vector vecA(3.0f, 4.0f);
    Vector vecB(7.0f, 1.0f);
    vecA += vecB;
    return(vecA.x == 10.0f && vecA.y == 5.0f);
}

bool test_subtraction_assignment() {
    Vector vecA(10.0f, 5.0f);
    Vector vecB(7.0f, 1.0f);
    vecA -= vecB;
    return(vecA.x == 3.0f && vecA.y == 4.0f);
}

bool test_scalar_multiplication_assignment() {
    Vector vecA(5.0, 2.0f);
    float numB(3.0f);
    vecA *= numB;
    return(vecA.x == 15.0f && vecA.y == 6.0f);
}

bool test_scalar_division_assignment() {
    Vector vecA(15.0f, 6.0f);
    float numB(3.0f);
    vecA /= numB;
    return(vecA.x == 5.0f && vecA.y == 2.0f);
}

bool test_basic_addition() {
    Vector vecA(3.0f, 4.0f);
    Vector vecB(7.0f, 1.0f);
    Vector result = vecA + vecB
    return(result.x == 10.0f && result.y == 5.0f);
}

bool test_basic_subtraction() {
    Vector vecA(10.0f, 5.0f);
    Vector vecB(7.0f, 1.0f);
    Vector result = vecA + vecB
    return(result.x == 3.0f && result.y == 4.0f);
}

bool test_basic_scalar_multiplication() {
    Vector vecA(5.0, 2.0f);
    float numB(3.0f);
    Vector result = vecA * numB;
    return(result.x == 15.0f && result.y == 6.0f);
}

bool test_basic_scalar_division() {
    Vector vecA(15.0f, 6.0f);
    float numB(3.0f);
    Vector result = vecA / numB;
    return(result.x == 5.0f && result.y == 2.0f);
}

bool test_basic_scalar_division() {
    Vector vecA(15.0f, 6.0f);
    float numB(3.0f);
    Vector result = vecA / numB;
    return(result.x == 5.0f && result.y == 2.0f);
}

bool test_dot_product() {
    Vector vecA(3.0f, 4.0f);
    Vector vecB(2.0f, -1.0f);
    float result = dot(vecA, vecB)
    return result == 2.0f; // Expected: (3 * 2) + (4 * -1) = 6 - 4 = 2
}

bool test_vector_magnitude() {
    Vector vecA(3.0f, 4.0f);
    Vector result = magnitude(vecA)
    return result == 5.0f;

// TODO: Additional Unit Tests (Multiple Cases) 
    // Dot Product (Special Cases)
    // Scalar Cross Product
    // Perpendicular Vector

// TODO: Geometry Unit Tests
    // Relative Angle
    

// Tests Structure
struct TestCase {
    const char* name;
    bool (*fn)(); // Test Function Pointer
};


int main() {

    // Test Harness
    std::vector<TestCase> tests = { // Array of Tests (To Run)
        {"Unary Negation", test_unary_negation},
        {"Addition Assignment", test_addition_assignment},
        {"Subtraction Assignment", test_subtraction_assignment},
        {"Scalar Multiplication Assignment", test_scalar_multiplication_assignment},
        {"Scalar Division Assignment", test_scalar_division_assignment},
        // ...
        {"Vector Magnitude", test_vector_magnitude}
    };
    
    // Loop (For Each Test)
    int numPassed = 0
    for (auto& test : tests) {
        bool pass = test.fn(); // Run Test
        if (pass) numPassed++; // Count Successful Tests
        std::cout << test.name << ":"
        << (pass ? "PASS" : "FAIL") << "\n"; // Output Status (Per Test)
    
    // Tests Summary
    std::cout << "\n Passed: " << numPassed
    << "\nFailed: " << (tests.size() - numPassed) << "\n";

    return 0;
}