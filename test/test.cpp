#include "brute_force.hpp"
#include <cassert>

int main() {
    VectorDB db;
    db.load_from_file("data/vectors.txt");

    BruteForceIndex index;
    index.build(db);

    std::vector<float> query{0.4f, 0.3f, 0.1f, 0.2f};
    auto result = index.search(query, 3);

    assert(result.size() == 3);
    assert(result[0] >= 0 && result[0] <= db.size());

    return 0;
}