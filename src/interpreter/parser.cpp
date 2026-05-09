#include "parser.h"
#include "ast.h"
#include "token.h"

#include <initializer_list>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens) {}

Token Parser::peek() const { return tokens[current]; }
Token Parser::peek(size_t n) const { return tokens[current + n]; }

Token Parser::advance() {
    if (!is_at_end())
        ++current;
    return tokens[current - 1];
}

bool Parser::is_at_end() const { return peek().type == TokenType::EndOfFile; }

bool Parser::check(TokenType type) const {
    return !is_at_end() && peek().type == type;
}

bool Parser::check(
    TokenType type, std::initializer_list<std::string_view> lexemes) const {
    if (is_at_end() || peek().type != type)
        return false;
    for (auto lexeme : lexemes) {
        if (peek().lexeme == lexeme)
            return true;
    }
    return false;
}

std::optional<Token> Parser::match(TokenType type) {
    if (check(type)) {
        return advance();
    }
    return std::nullopt;
}

std::optional<Token> Parser::match(
    TokenType type, std::initializer_list<std::string_view> lexemes) {
    if (check(type, lexemes)) {
        return advance();
    }
    return std::nullopt;
}

Expression Parser::parse_term() {
    Expression expr = parse_factor();
    while (auto t_op = match(TokenType::Operator, {"*", "%"})) {
        std::string op {tokens[current - 1].lexeme.data(),
            tokens[current - 1].lexeme.size()};
        Expression right = parse_factor();
        expr = BinaryOp {op, std::make_unique<Expression>(std::move(expr)),
            std::make_unique<Expression>(std::move(right))};
    }
    return expr;
}

Expression Parser::parse_factor() {
    if (auto t_name = match(TokenType::Number)) {
        big_Z val {std::string {
            t_name.value().lexeme.data(), t_name.value().lexeme.size()}};
        return Number {val};
    }

    if (auto t_id = match(TokenType::Identifier)) {
        return Variable {std::string {
            t_id.value().lexeme.data(), t_id.value().lexeme.size()}};
    }

    if (match(TokenType::LeftParen)) {
        Expression expr = parse_expression();
        if (!match(TokenType::RightParen))
            throw std::runtime_error("Expected ')'");
        return expr;
    }
    throw std::runtime_error("Unexpected token in factor, line " +
                             std::to_string(peek().line) + " column " +
                             std::to_string(peek().column));
}

Block Parser::parse_block() {
    if (!match(TokenType::LeftBrace)) {
        throw std::runtime_error("Expected '{' to start block");
    }

    std::vector<Statement> stmts;
    while (!check(TokenType::RightBrace) || !is_at_end()) {
        stmts.push_back(parse_statement());
    }

    if (!match(TokenType::RightBrace)) {
        throw std::runtime_error("Expected '}' to end block");
    }

    return Block {std::move(stmts)};
}

Expression Parser::parse_expression() {
    Expression expr = parse_term();
    while (auto t_op = match(TokenType::Operator, {"+", "-"})) {
        std::string op {t_op.value().lexeme.data(), t_op.value().lexeme.size()};
        Expression right = parse_term();
        expr = BinaryOp {op, std::make_unique<Expression>(std::move(expr)),
            std::make_unique<Expression>(std::move(right))};
    }
    return expr;
}

Statement Parser::parse_statement() {
    if (match(TokenType::KeywordPrint)) {
        Expression value = parse_expression();
        return Print {std::make_unique<Expression>(std::move(value))};
    }

    else if (auto t_type = match(TokenType::Type)) {
        if (auto t_name = match(TokenType::Identifier)) {
            std::string name = std::string {
                t_name.value().lexeme.data(), t_name.value().lexeme.size()};
            if (match(TokenType::Assign)) {
                Expression value = parse_expression();
                if ((*t_type).lexeme == "N")
                    return Assignment {name, Type::Nat,
                        std::make_unique<Expression>(std::move(value))};
                if ((*t_type).lexeme == "Z")
                    return Assignment {name, Type::Int,
                        std::make_unique<Expression>(std::move(value))};
                if ((*t_type).lexeme == "Q")
                    return Assignment {name, Type::Rat,
                        std::make_unique<Expression>(std::move(value))};
                if ((*t_type).lexeme == "P")
                    return Assignment {name, Type::Poly,
                        std::make_unique<Expression>(std::move(value))};
            } else
                throw std::runtime_error("Expected '=' after variable name");
        } else
            throw std::runtime_error("Expected variable name after type");
    }

    else if (match(TokenType::KeywordIf)) {
        Expression cond = parse_expression();
        Block body = parse_block();
        return If {
            std::make_unique<Expression>(std::move(cond)), std::move(body)};
    }

    else if (match(TokenType::KeywordWhile)) {
        Expression cond = parse_expression();
        Block body = parse_block();
        return While {
            std::make_unique<Expression>(std::move(cond)), std::move(body)};
    }

    Expression expr = parse_expression();
    return Assignment {"_", Type::Infer,
        std::make_unique<Expression>(std::move(expr))}; // Anonymous expression
}

std::vector<Statement> Parser::parse() {
    std::vector<Statement> stmts;
    while (!is_at_end()) {
        stmts.push_back(parse_statement());
    }
    return stmts;
}
