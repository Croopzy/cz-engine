#include <iostream>
#include "test/utilities/test_utils.hpp"
#include "src/Cryoze/maths/Vector.hpp"


///// Vector Unit Tests /////


/// Vector Methods ///

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


/// Vector Operations ///

bool test_basic_addition() {
    Vector vecA(3.0f, 4.0f);
    Vector vecB(7.0f, 1.0f);
    Vector result = vecA + vecB;
    return(result.x == 10.0f && result.y == 5.0f);
}

bool test_basic_subtraction() {
    Vector vecA(10.0f, 5.0f);
    Vector vecB(7.0f, 1.0f);
    Vector result = vecA - vecB;
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


bool test_dot_product_acute() {
    Vector vecA(3.0f, 4.0f);
    Vector vecB(2.0f, 1.0f);
    float result = dot(vecA, vecB); // (3 * 2) + (4 * 1) = 10
    return result == 10.0f; // Positive: Acute Angle
}

bool test_dot_product_obtuse() {
    Vector vecA(2.0f, 3.0f);
    Vector vecB(-4.0f, 1.0f);
    float result = dot(vecA, vecB); // (2 * -4) + (3 * 1) = -5
    return result == -5.0f; // Negative: Obtuse Angle
}

bool test_dot_product_zero() {
    Vector vecA(1.0f, 0.0f);
    Vector vecB(0.0f, 5.0f);
    float result = dot(vecA, vecB); // (1 * 0) + (0 * 5) = 0
    return result == 0.0f; // Zero: Perpendicular
}


bool test_cross_product_clockwise() { // vecB Clockwise From vecA
    Vector vecA(0.0f, 1.0f);
    Vector vecB(1.0f, 0.0f);
    float result = cross(vecA, vecB);
    return result == -1.0f; // Negative: Clockwise
}

bool test_cross_product_anticlockwise() { // vecB Anti-Clockwise From vecA
    Vector vecA(1.0f, 0.0f);
    Vector vecB(0.0f, 1.0f);
    float result = cross(vecA, vecB);
    return result == 1.0f; // Positive: Anti-Clockwise
}

bool test_cross_product_parallel() { // vecA Parallel To vecB
    Vector vecA(2.0f, 2.0f);
    Vector vecB(4.0f, 4.0f);
    float result = cross(vecA, vecB);
    return result == 0.0f; // Zero: Parallel (Same Direction)
}

bool test_cross_product_antiparallel() { // vecA Anti-Parallel To vecB
    Vector vecA(1.0f, 2.0f);
    Vector vecB(-1.0f, -2.0f);
    float result = cross(vecA, vecB);
    return result == 0.0f; // Zero: Parallel (Opposite Directions)
}


bool test_vector_magnitude() {
    Vector vecA(3.0f, 4.0f);
    float result = magnitude(vecA);
    return result == 5.0f;
}

bool test_vector_unit_basic() {
    Vector vecA(3.0f, 4.0f);
    Vector vecB(0.6f, 0.8f);
    Vector result = normalise(vecA);
    return (result.x == vecB.x) && (result.y == vecB.y);
}

bool test_vector_unit_zero() {
    Vector vecA(0.0f, 0.0f);
    Vector result = normalise(vecA);
    return (result.x == vecA.x) && (result.y == vecA.y);
}

bool test_vector_unit_idempotent() {
    Vector vecA(1.0f, 0.0f);
    Vector result = normalise(vecA);
    return (result.x == vecA.x) && (result.y == vecA.y);
}

bool test_vector_perpendicular() {
    Vector vecA(1.0f, 0.0f);
    Vector vecB(0.0f, 1.0f);
    Vector result = perpendicular(vecA);
    return (result.x == vecB.x) && (result.y == vecB.y);
}

/// Geometric Functions ///


bool test_angle_case_same() {
    Vector vecA(3.0f, 4.0f);
    Vector vecB(6.0f, 8.0f);
    return angle(vecA, vecB) == 0.0f;
}

bool test_angle_case_acute() {
    Vector vecA(1.0f, 0.0f);
    Vector vecB(1.0f, 1.0f);
    return angle(vecA, vecB) == MathsConstants::PI / 4;
}

bool test_angle_case_perpendicular() {
    Vector vecA(1.0f, 0.0f);
    Vector vecB(0.0f, 1.0f);
    return angle(vecA, vecB) == MathsConstants::PI / 2;
}

bool test_angle_case_opposite() {
    Vector vecA(1.0f, 0.0f);
    Vector vecB(-1.0f, 0.0f);
    return angle(vecA, vecB) == MathsConstants::PI;
}



///// Test Harness: Maths /////

namespace tests::modules {
void runMathsTests(const bool showCases) {

    std::vector<TestCase> mathsTests = {
        {"Unary Negation", test_unary_negation},
        {"Addition Assignment", test_addition_assignment},
        {"Subtraction Assignment", test_subtraction_assignment},
        {"Scalar Multiplication Assignment", test_scalar_multiplication_assignment},
        {"Scalar Division Assignment", test_scalar_division_assignment},
        {"Basic Addition", test_basic_addition},
        {"Basic Subtraction", test_basic_subtraction},
        {"Basic Scalar Multiplication", test_basic_scalar_multiplication},
        {"Basic Scalar Division", test_basic_scalar_division},
        {"Dot Product (Acute)", test_dot_product_acute},
        {"Dot Product (Obtuse)", test_dot_product_obtuse},
        {"Dot Product (Zero)", test_dot_product_zero},
		{"Cross Product (Clockwise)", test_cross_product_clockwise},
		{"Cross Product (Anti-Clockwise)", test_cross_product_anticlockwise},
		{"Cross Product (Parallel)", test_cross_product_parallel},
		{"Cross Product (Anti-Parallel)", test_cross_product_antiparallel},
        {"Scalar Magnitude of Vector", test_vector_magnitude},
        {"Basic Normalisation (Unit Vector)", test_vector_unit_basic},
        {"Zero Vector Normalisation (Unit Vector)", test_vector_unit_zero},
        {"Idempotent Normalisation (Unit Vector)", test_vector_unit_idempotent},
        {"Perpendicular Vector", test_vector_perpendicular},
        {"Angle Between Vectors (Same)", test_angle_case_same},
        {"Angle Between Vectors (Acute)", test_angle_case_acute},
        {"Angle Between Vectors (Perpendicular)", test_angle_case_perpendicular},
        {"Angle Between Vectors (Opposite)", test_angle_case_opposite},
    };

    tests::detail::runTestGroup("MATHS", mathsTests, showCases);

} // End runMathsTests() Function
} // End tests::modules Namespace