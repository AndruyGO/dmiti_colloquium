#include "lexer.h"
#include "token.h"

#include <cctype>
#include <cstddef>
#include <string_view>
#include <vector>

Lexer::Lexer(std::string_view input) : source(input) {}

char Lexer::peek() const { return is_at_end() ? '\0' : source[current]; }

char Lexer::advance() {
    char c = peek();
    ++current;
    ++column;
    return c;
}

bool Lexer::is_at_end() const { return current >= source.size(); }

void Lexer::skip_whitespace() {
    while (!is_at_end()) {
        char c = peek();

        if (c == ' ' || c == '\t')
            advance();
        else if (c == '\n') {
            ++line;
            column = 1;
            advance();
        } else
            break;
    }
}

Token Lexer::read_number() {
    size_t number_start = current;
    while (isdigit(peek()))
        advance();
    auto lexeme = source.substr(number_start, current - number_start);
    return Token {TokenType::Number, lexeme, line, column};
}

Token Lexer::read_identifier_or_keyword() {
    size_t id_start = current;
    while (isalnum(peek()) || peek() == '_' || peek() == '^')
        advance();

    auto text = source.substr(id_start, current - id_start);

    if (text == "print")
        return Token {TokenType::KeywordPrint, text, line, column};
    if (text == "if")
        return Token {TokenType::KeywordIf, text, line, column};
    if (text == "while")
        return Token {TokenType::KeywordWhile, text, line, column};
    if (text == "N" || text == "Z" || text == "Q" || text == "P")
        return Token {TokenType::Type, text, line, column};

    return Token {TokenType::Identifier, text, line, column};
}

Token Lexer::read_operator_or_symbol() {
    char c = advance();
    switch (c) {
    case '+':
    case '-':
    case '*':
    case '%':
        return Token {
            TokenType::Operator, source.substr(current - 1, 1), line, column};
    case '/':
        if (peek() == '/') {
            advance();
            return Token {TokenType::Operator, source.substr(current - 2, 2),
                line, column};
        } else {
            return Token {
                TokenType::Operator, source.substr(current - 1, 1), line, column};
        }
    case '=':
        return Token {TokenType::Assign, "=", line, column};
    case '(':
        return Token {TokenType::LeftParen, "(", line, column};
    case ')':
        return Token {TokenType::RightParen, ")", line, column};
    case '{':
        return Token {TokenType::LeftBrace, "{", line, column};
    case '}':
        return Token {TokenType::RightBrace, "}", line, column};

    case ';':
        return Token {TokenType::Semicolon, ";", line, column};

    default:
        return Token {
            TokenType::Unknown, source.substr(current - 1, 1), line, column};
    }
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;

    while (!is_at_end()) {
        skip_whitespace();
        char c = peek();
        if (isdigit(c))
            tokens.push_back(read_number());
        else if (isalpha(c))
            tokens.push_back(read_identifier_or_keyword());
        else
            tokens.push_back(read_operator_or_symbol());
    }

    tokens.push_back(Token {TokenType::EndOfFile, "", line, column});
    return tokens;
}
