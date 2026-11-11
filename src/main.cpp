#include "file_scanner.h"
#include "file_utils.h"
#include "parse.h"

#include <iostream>
#include <vector>
#include <filesystem>

int main(int argc, char* argv[]) {
    std::cout << "======================" << std::endl;
    std::cout << "       Moonpack       " << std::endl;
    std::cout << "======================" << std::endl;

    std::cout << "Scanning project..." << std::endl << std::endl;

    try {
        if (argc < 2) {
            std::cerr << "[ERROR] " << "Please input dir name" << std::endl;
            return 1;
        }

        std::filesystem::path projectPath = argv[1];

        file_scanner scanner;

        auto files = scanner.scan(projectPath);

        for (const auto& file : files) {
            std::cout << "------------------------" << std::endl;
            std::cout << "[FOUND] " << file.string() << std::endl;
            auto imports = parseImports(read_file(file.string()));
            for (const auto& impo : imports) {
                std::cout << impo.names << "  <===  " << impo.path << std::endl;
            }
            std::cout << "------------------------" << std::endl << std::endl;
        }

        std::cout << "Total files: " << files.size() << '\n';
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
