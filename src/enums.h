#pragma once

#include <string>
#include <cstddef>

enum class TokenType {
    Identifier,
    Keyword,
    Number,
    String,

    Operator,

    LeftParen,
    RightParen,
    LeftBrace,
    RightBrace,
    LeftBracket,
    RightBracket,

    Semicolon,
    Comma,
    Dot,

    EndOfFile,
    Unknown
};

struct Token {
    TokenType type;
    std::string value;

    size_t start;
    size_t end;
};