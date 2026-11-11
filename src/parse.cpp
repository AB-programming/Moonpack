#include "parse.h"

#include <string>
#include <regex>

std::vector<ImportEntry> parseImports(const std::string &code) {
    // match import lines
    std::regex pattern(
        R"(import\s*\{\s*([^}]+)\s*\}\s*from\s*['"]([^'"]+)['"]\s*;?)"
    );

    auto begin = std::sregex_iterator(
        code.begin(), code.end(), pattern
    );

    auto end = std::sregex_iterator();

    std::vector<ImportEntry> res;

    for (auto it = begin; it != end; ++it) {
        res.push_back({(*it)[1].str(), (*it)[2].str()});
    }

    return res;
}