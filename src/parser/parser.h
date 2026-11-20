#pragma once

#include "../lexer/lexer.h"

#include <vector>
#include <memory>

class Parser {
private:
    std::vector<Token> tokens;
    size_t pos = 0;

    Token& current();

    Token advance();

    bool match(TokenType type);

    Token consume(TokenType type);
public:
    explicit Parser(std::vector<Token> t) : tokens(std::move(t)) {}

    FunctionDeclaration* parseFunctionDeclaration();

    ASTNode* parseStatement();

    std::unique_ptr<ASTNode> parseProgram();
};