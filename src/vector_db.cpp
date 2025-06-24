#include "vector_db.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

bool VectorDB::load_from_file(const std::string &file_path) {
    std::ifstream infile(file_path);
    if (!infile.is_open()) {
        std::cerr << "Failed to open file: " << file_path << std::endl;
        return false;
    }

    vectors_.clear();
    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::vector<float> vec;
        float value;
        while (iss >> value) {
            vec.push_back(value);
        }
        if (!vec.empty()) {
            vectors_.push_back(vec);
        }
    }
    return true;
}

const std::vector<float> &VectorDB::get_vector(int index) const {
    return vectors_.at(index);
}

size_t VectorDB::size() const {
    return vectors_.size();
}