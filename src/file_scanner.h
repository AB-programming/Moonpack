#pragma once

#include <filesystem>
#include <vector>

class file_scanner {
public:
    [[nodiscard]] std::vector<std::filesystem::path> scan(
        const std::filesystem::path& root
    ) const;
};