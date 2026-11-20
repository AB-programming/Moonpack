#pragma once

#include <string>
#include <cstddef>
#include <vector>
#include <memory>

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

enum class NodeType {
    Program,

    VariableDeclaration,
    VariableDeclarator,

    FunctionDeclaration,
    FunctionExpression,
    ArrowFunctionExpression,

    BlockStatement,
    ReturnStatement,
    ExpressionStatement,

    CallExpression,
    Identifier,
    Literal,

    BinaryExpression,
    AssignmentExpression,

    Unknown
};

struct Token {
    TokenType type;
    std::string value;

    size_t start;
    size_t end;
};

struct ASTNode {
    NodeType type;

    size_t start = 0;
    size_t end = 0;

    std::vector<std::unique_ptr<ASTNode>> children;

    virtual ~ASTNode() = default;

    explicit ASTNode(NodeType t) : type(t) {}
};

struct FunctionDeclaration : ASTNode {
    std::string name;
    std::vector<std::string> params;
    std::vector<ASTNode *> body;

    FunctionDeclaration() : ASTNode(NodeType::FunctionDeclaration) {}
};

struct Program : ASTNode {
    std::vector<ASTNode *> body;

    Program() : ASTNode(NodeType::Program) {}
};