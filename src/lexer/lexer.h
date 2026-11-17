# pragma once

#include "../enums.h"

#include <string>
#include <vector>

class Lexer {
private:
    std::string source;
    size_t pos = 0;

    char peek(size_t offset = 0);
    char advance();

public:
    explicit Lexer(std::string code);
    std::vector<Token> tokenize();
};

