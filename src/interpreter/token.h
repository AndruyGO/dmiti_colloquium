#pragma once

#include <string_view>

enum class TokenType {
    Number,

    Identifier,
    Operator,
    Assign,

    KeywordPrint,
    KeywordIf,
    KeywordWhile,
    KeywordFunc,

    Type,

    LeftParen,
    RightParen,
    LeftBrace,
    RightBrace,

    Semicolon,

    EndOfFile,
    Unknown
};

struct Token {
    TokenType type;
    std::string_view lexeme;
    int line;
    int column;
};

std::ostream& operator<<(std::ostream& os, const Token& obj);
