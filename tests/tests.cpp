#include <iostream>
#include "maths/vector.hpp"
#include "maths/geometry.hpp"

int main() {


    // Vector Unit Tests
    bool test_unary_negation() {
        Vector vecA(3.0f, 4.0f);
        Vector result = -vecA;
        return(result.x == -3.0f && result.y == -4.0f);
    }
    
    bool test_addition_assignment() {
        Vector vecA(3.0f, 4.0f);
        vector vecB(7.0f, 1.0f);
        vecA += vecB;
        return(vecA.x == 10.0f && vecA.y == 5.0f);
    }

    bool test_subtraction_assignment() {
        vector vecA(10.0f, 5.0f);
        Vector vecB(7.0f, 1.0f);
        vecA -= vecB;
        return(vecA.x == 3.0f && vecA.y == 4.0f);
    }

    bool test_addition_assignment() {
        Vector vecA(3.0f, 4.0f);
        vector vecB(7.0f, 1.0f);
        vecA += vecB;
        return(vecA.x == 10.0f && vecA.y == 5.0f);
    }

    bool test_scalar_multiplication_assignment() {
        vector vecA(5.0, 2.0f);
        float numB(3.0f);
        vecA *= numB;
        return(vecA.x == 15.0f && vecA.y == 6.0f);
    }

    bool test_scalar_division_assignment() {
        vector vecA(15.0f, 6.0f);
        float numB(3.0f);
        vecA /= numB;
        return(vecA.x == 5.0f && vecA.y == 2.0f);
    }

    return 0;
}