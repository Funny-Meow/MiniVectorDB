#include "brute_force.hpp"
#include <chrono>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>

int main() {
    int top_k = 3;
    VectorDB db;
    db.load_from_file("data/vectors.txt");

    BruteForceIndex index;
    index.build(db);

    std::vector<float> query;
    std::ifstream infile("data/query.txt");
    std::string line;
    std::getline(infile, line);
    std::istringstream iss(line);
    float value;
    while(iss >> value) {
        query.push_back(value);
    }

    assert(query.size() == 1024);

    auto start = std::chrono::high_resolution_clock::now();
    auto result = index.search(query, top_k);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Top-3 search time: " << elapsed.count() << " seconds.\n";
    for (int i = 0; i < top_k; ++i) {
        for (auto a : db.get_vector(result[i])) {
            std::cout << a << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}