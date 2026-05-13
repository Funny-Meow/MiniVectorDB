#pragma once
#include <cstddef>
#include <string>

namespace minivdb {
    using VectorId = std::size_t;
    enum class MetricType {
        L2,
        COSINE
    };

    struct SearchResult {
        VectorId id;
        float score;
    };

    struct SearchOptions {
        std::size_t top_k = 10;
        MetricType metric = MetricType::L2;
    };
}; // namespace minivdb
