#include "file_utils.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// Read code content from file
std::string read_file(const std::string& path) {
    std::ifstream file(path);

    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + path);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}