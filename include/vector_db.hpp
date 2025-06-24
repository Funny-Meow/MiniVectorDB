#pragma once
#include <string>
#include <vector>

class VectorDB {
public:
    // Load vectors from a text file. Each line should represent a vecotr of floats separated by spaces.
    bool load_from_file(const std::string &file_path);

    // Get the vector at the given index.
    const std::vector<float> &get_vector(int index) const;

    // Return the number of loaded vectors.
    size_t size() const;

private:
    // Internal storage for all loaded vectors.
    std::vector<std::vector<float>> vectors_;
};