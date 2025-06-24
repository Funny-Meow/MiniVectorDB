#pragma once
#include "vector_db.hpp"
#include <vector>

class Index {
public:
    virtual void build(const VectorDB &db) = 0;
    virtual std::vector<int> search(const std::vector<float> &query, int top_k) = 0;
    virtual ~Index() {}
};