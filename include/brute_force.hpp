#pragma once
#include "index.hpp"
#include "vector_db.hpp"
#include <vector>

class BruteForceIndex : public Index {
public:
    void build(const VectorDB &db) override;
    std::vector<int> search(const std::vector<float> &query, int top_k) override;

private:
    const VectorDB *db_;
};