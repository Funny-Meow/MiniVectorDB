#pragma once
#include "types.hpp"
#include "vector_db.hpp"
#include <vector>
namespace minivdb {
    class Index {
    public:
        virtual void build(const VectorDB &db) = 0;
        virtual std::vector<SearchResult> search(const std::vector<float> &query, const SearchOptions &options) const = 0;
        virtual std::size_t dimension() const = 0;
        virtual std::size_t size() const = 0;
        virtual ~Index() = default;
    };
};