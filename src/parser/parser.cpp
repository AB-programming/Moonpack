#include "parser.h"

#include <stdexcept>

Token& Parser::current() {
    return tokens[pos];
}

Token Parser::advance() {
    return tokens[pos++];
}

bool Parser::match(TokenType type) {
    if (current().type == type) {
        advance();
        return true;
    }
    return false;
}

Token Parser::consume(TokenType type) {
    if (current().type != type) {
        throw std::runtime_error("Unexpected token: " + current().value);
    }

    return advance();
}