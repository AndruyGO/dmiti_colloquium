#pragma once
#include "token.h"

#include <cstddef>
#include <string_view>
#include <vector>
#include <iostream>

class Lexer {
  public:
    Lexer(std::string_view input);
    std::vector<Token> tokenize();

  private:
    std::string_view source;
    size_t start = 0;
    size_t current = 0;
    int line = 1;
    int column = 1;

    char peek() const;
    char advance();
    bool is_at_end() const;

    void skip_whitespace();
    Token read_number();
    Token read_identifier_or_keyword();
    Token read_operator_or_symbol();
};
