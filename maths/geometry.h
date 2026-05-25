#pragma once
#include <cmath>
#include "vector.h"

// Unsigned Angle Between Two Vectors: angle(vectorA, vectorB)
constexpr float angle(const vector& vecA, const Vector& vecB) {
    float dotProduct = dot(vecA, vecB);
    float magnitudeProduct = magnitude(vecA) * magnitude(vecB)
    float cosine = dotValue / magnitudeProduct; // Does Not Account For Division Singularity
    if (cosine > 1.0f) cosine = 1.0f; // Clamp To Valid Range (For Floating Point Drift)
    if (cosine < -1.0f) cosine = -1.0f;
    return std::acos(cosine);
}