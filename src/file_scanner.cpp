#include "file_scanner.h"

#include <stdexcept>

std::vector<std::filesystem::path> file_scanner::scan(const std::filesystem::path& root) const {
    namespace fs = std::filesystem;

    if (!fs::exists(root)) {
        throw std::runtime_error("Pro dir does not exist");
    }

    if (!fs::is_directory(root)) {
        throw std::runtime_error("Path is not a dir");
    }

    std::vector<fs::path> files;

    for (const auto& entry : fs::recursive_directory_iterator(root)) {
        if (entry.is_regular_file()) {
            files.push_back(entry.path());
        }
    }

    return files;
}