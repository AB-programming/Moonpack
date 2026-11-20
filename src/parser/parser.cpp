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

FunctionDeclaration* Parser::parseFunctionDeclaration() {
    consume(TokenType::Keyword);
    auto* func = new FunctionDeclaration();
    func->name = consume(TokenType::Identifier).value;
    consume(TokenType::LeftParen);

    if (current().type != TokenType::RightParen) {
        do {
            func->params.push_back(
                consume(TokenType::Identifier).value
            );
        } while (match(TokenType::Comma));
    }

    consume(TokenType::RightParen);

    // TODO handle parseBlockStatement
}

ASTNode* Parser::parseStatement() {
    if (current().value == "function") {
        return parseFunctionDeclaration();
    } else if (current().value == "return") {
        // TODO return parseReturnStatement
    }

    throw std::runtime_error("Unknown statement");
}

std::unique_ptr<ASTNode> Parser::parseProgram() {
    auto* program = new Program();
    while (current().type != TokenType::EndOfFile) {

    }
}