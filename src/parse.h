#ifndef PARSE_H
#define PARSE_H

#include <string>
#include <vector>

// Import object structure
struct ImportEntry {
    std::string names;
    std::string path;
};

std::vector<ImportEntry> parseImports(const std::string &code);

#endif