#include "utils.hpp"
#include <stdexcept>
#include <cmath>

float l2_distance(const std::vector<float> &a, const std::vector<float> &b) {
    if (a.size() != b.size())
        throw std::invalid_argument("Dimension mismatch.");

    float sum = 0.0f;
    for (size_t i = 0; i < a.size(); ++i) {
        float diff = a[i] - b[i];
        sum += diff * diff;
    }
    return sum;
}


float cosine_similarity(const std::vector<float> &a, const std::vector<float> &b) {
    if (a.size() != b.size()) 
        throw std::invalid_argument("Dimension mismatch.");

    float dot = 0.0f, norm_a = 0.0f, norm_b = 0.0f;
    for (size_t i = 0; i < a.size(); ++i) {
        dot += a[i] * b[i];
        norm_a += a[i] * a[i];
        norm_b += b[i] * b[i];
    }
    return dot / (std::sqrt(norm_a * norm_b) + 1e-6);
}