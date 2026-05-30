#pragma once
#include <cmath>
#include "engine/maths/constants.hpp"
#include "engine/maths/vector.hpp"

// Unsigned Angle Between Two Vectors (Relative Angle, Unit: Radians): angle(vectorA, vectorB)
inline float angle(const Vector& vecA, const Vector& vecB) {
    float dotProduct = dot(vecA, vecB);
    float magnitudeProduct = magnitude(vecA) * magnitude(vecB);
    if (magnitudeProduct <= MathsConstants::EPSILON) return 0.0f;
    float cosine = dotProduct / magnitudeProduct; // Does Not Account For Division Singularity
    if (cosine > 1.0f) cosine = 1.0f; // Clamp To Valid Range (For Floating Point Drift)
    if (cosine < -1.0f) cosine = -1.0f;
    return std::acos(cosine);
}
