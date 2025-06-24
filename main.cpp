// #include "vector_db.hpp"
#include "brute_force.hpp"
#include <iostream>
#include <sstream>

int main() {
    VectorDB db;
    if (!db.load_from_file("data/vectors.txt")) {
        std::cerr << "Failed to load vector data." << std::endl;
    }

    std::cout << "Loaded " << db.size() << " vectors." << std::endl;

    for (size_t i = 0; i < db.size(); ++i) {
        const auto &vec = db.get_vector(i);
        std::cout << "Vecotr" << i << ": ";
        for (auto val : vec) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    BruteForceIndex index;
    index.build(db);
    int top_k = 3;
    std::cout << "Enter top-k value (default = 3): ";
    std::string topk_str;
    std::getline(std::cin, topk_str);
    if (!topk_str.empty())
        top_k = std::stoi(topk_str);

    std::string line;
    while (true) {
        std::cout << "Enter query vector (or \"exit\"): ";
        std::getline(std::cin, line);
        if (line == "exit")
            break;

        std::istringstream iss(line);
        std::vector<float> query;
        float val;
        while (iss >> val)
            query.push_back(val);
        if (query.size() != db.get_vector(0).size()) {
            std::cout << "Invalid dimension!\n";
            continue;
        }
        auto result = index.search(query, top_k);
        std::cout << "Top-" << top_k << " results: ";
        for (int i : result){
            auto target =  db.get_vector(i);
            for (auto t : target) std::cout << t << " ";
            std::cout << "\n";
        }
    }

    // std::vector<float> query({0.4f, 0.3f, 0.1f, 0.2f});

    return 0;
}