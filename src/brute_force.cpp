#include "brute_force.hpp"
#include "utils.hpp"
#include <cmath>
#include <queue>
#include <stdexcept>

void BruteForceIndex::build(const VectorDB &db) {
    db_ = &db;
}

std::vector<int> BruteForceIndex::search(const std::vector<float> &query, int top_k) {
    if (!db_)
        throw std::runtime_error("Index not built. Call build() first.");

    using Pair = std::pair<float, int>; // pair<distance, index>
    std::priority_queue<Pair, std::vector<Pair>, std::greater<>> min_heap;

    for (size_t i = 0; i < db_->size(); ++i) {
        const auto &vec = db_->get_vector(i);
        if (vec.size() != query.size()) {
            throw std::invalid_argument("Vector dimensionality mismatch.");
        }

        // L2 distance
        float dist = l2_distance(query, vec);
        min_heap.emplace(dist, i);
    }

    std::vector<int> result;
    for (int i = 0; i < top_k && !min_heap.empty(); ++i) {
        result.push_back(min_heap.top().second);
        min_heap.pop();
    }

    return result;
}