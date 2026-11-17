#include "lexer.h"

#include <cctype>

char Lexer::peek(size_t offset) {
    if (pos + offset >= source.size())
        return '\0';
    return source[pos + offset];
}

char Lexer::advance() {
    return source[pos++];
}

Lexer::Lexer(std::string code) : source(std::move(code)) {}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;

    while (pos < source.size()) {
        char c = peek();

        if (std::isspace(static_cast<unsigned char>(c))) {
            advance();
            continue;
        }

        size_t start = pos;

        // Identifier
        if (std::isalpha(static_cast<unsigned char>(c)) ||
            c == '_' || c == '$') {
            std::string value;

            while (std::isalnum(static_cast<unsigned char>(peek())) ||
                   peek() == '_' || peek() == '$') {
                value += advance();
            }

            TokenType type = TokenType::Identifier;

            if (value == "const" ||
                value == "let" ||
                value == "var" ||
                value == "function" ||
                value == "if" ||
                value == "else" ||
                value == "new" ||
                value == "class") {
                type = TokenType::Keyword;
            }

            tokens.push_back({
                type, value, start, pos
            });

            continue;
        }

        // Number
        if (std::isdigit(static_cast<unsigned char>(c))) {
            std::string value;

            while (std::isdigit(static_cast<unsigned char>(peek()))) {
                value += advance();
            }

            tokens.push_back({
                TokenType::Number, value, start,pos
            });

            continue;
        }

        // String
        if (c == '"' || c == '\'') {
            char quote = advance();

            std::string value;

            while (peek() != '\0' && peek() != quote) {
                if (peek() == '\\') {
                    value += advance();
                    if (peek() != '\0')
                        value += advance();
                } else {
                    value += advance();
                }
            }

            if (peek() == quote) {
                advance();
            }

            tokens.push_back({
                TokenType::String, value, start, pos
            });

            continue;
        }

        // Punctuation
        TokenType type = TokenType::Unknown;

        switch (advance()) {
            case '(':
                type = TokenType::LeftParen;
                break;
            case ')':
                type = TokenType::RightParen;
                break;
            case '{':
                type = TokenType::LeftBrace;
                break;
            case '}':
                type = TokenType::RightBrace;
            case '[':
                type = TokenType::LeftBracket;
            case ']':
                type = TokenType::RightBracket;
            case '=':
            case '+':
            case '-':
            case '*':
            case '/':
                type = TokenType::Operator;
                break;
            default:
                break;
        }

        tokens.push_back({
            type, source.substr(start, pos - start), start, pos
        });
    }

    tokens.push_back({
        TokenType::EndOfFile, "", pos, pos
    });

    return tokens;
}