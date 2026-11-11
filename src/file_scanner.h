#ifndef FILE_SCANNER_H
#define FILE_SCANNER_H

#include <filesystem>
#include <vector>

class file_scanner {
public:
    [[nodiscard]] std::vector<std::filesystem::path> scan(
        const std::filesystem::path& root
    ) const;
};

#endif