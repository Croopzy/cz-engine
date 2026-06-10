#pragma once

// Tests Structure
struct TestCase {
    const char* name;
    bool (*fn)(); // Test Function Pointer
};

// Maths Test Function Declarations
bool test_unary_negation();
bool test_addition_assignment();
bool test_subtraction_assignment();
bool test_scalar_multiplication_assignment();
bool test_scalar_division_assignment();
bool test_basic_addition();
bool test_basic_subtraction();
bool test_basic_scalar_multiplication();
bool test_basic_scalar_division();
bool test_dot_product();
bool test_vector_magnitude();
bool test_angle_case_perpendicular();

// Maths Test Harness Declaration
void runMathsTests();