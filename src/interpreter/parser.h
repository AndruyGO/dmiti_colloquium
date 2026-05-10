#pragma once
#include "token.h"
#include "ast.h"

#include <optional>
#include <string_view>
#include <vector>

class Parser {
  public:
    Parser(const std::vector<Token>& tokens);
    std::vector<Statement> parse();

  private:
    const std::vector<Token>& tokens;
    size_t current = 0;

    Token peek() const;
    Token peek(size_t n) const;
    Token advance();
    bool is_at_end() const;
    bool check(TokenType type) const;
    bool check(
        TokenType type, std::initializer_list<std::string_view> lexemes) const;
    std::optional<Token> match(TokenType type);
    std::optional<Token> match(
        TokenType type, std::initializer_list<std::string_view> lexemes);

    Statement parse_statement();
    Expression parse_expression();
    Expression parse_term();
    Expression parse_factor();
    Block parse_block();
};
