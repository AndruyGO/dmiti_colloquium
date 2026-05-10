#include "token.h"

#include <iostream>

constexpr std::string_view getTokenTypeName(TokenType type) {
    switch (type) {
    case TokenType::Number:
        return "Number";
    case TokenType::Identifier:
        return "Identifier";
    case TokenType::Operator:
        return "Operator";
    case TokenType::Assign:
        return "Assign";

    case TokenType::KeywordPrint:
        return "KeywordPrint";
    case TokenType::KeywordIf:
        return "KeywordIf";
    case TokenType::KeywordWhile:
        return "KeywordWhile";

    case TokenType::Type:
        return "Type";

    case TokenType::LeftParen:
        return "LeftParen";
    case TokenType::RightParen:
        return "RightParen";
    case TokenType::LeftBrace:
        return "LeftBrace";
    case TokenType::RightBrace:
        return "RightBrace";

    case TokenType::Semicolon:
        return "Semicolon";

    case TokenType::EndOfFile:
        return "EndOfFile";
    case TokenType::Unknown:
        return "Unknown";
    default:
        return "Unknown";
    }
}

std::ostream& operator<<(std::ostream& out, const Token& token) {
    out << "Token{" << getTokenTypeName(token.type) << ", \"" << token.lexeme
        << "\", line " << token.line << ", column " << token.column << "}";
    return out;
}
