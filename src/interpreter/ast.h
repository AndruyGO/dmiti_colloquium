#pragma once
#include "../Module_2/integer.h"

#include <memory>
#include <string>
#include <variant>
#include <vector>

// I LOVE CIRCULAR DEPENDENCIES!!!!!!
// I LOVE FORWARD DECLARATIONS!!!
// CPP IS THE BEST LANGUAGE!!!
struct Number;
struct Variable;
struct BinaryOp;
struct Assignment;
struct Print;
struct Block;
struct If;
struct While;

using Expression = std::variant<Number, Variable, BinaryOp>;
using Statement = std::variant<Assignment, Print, If, While, Block>;

struct Number {
    big_Z value;
};

enum class Type {
    Nat,
    Int,
    Rat,
    Poly,
    Infer
};

struct Variable {
    std::string name;
};

struct BinaryOp {
    std::string op;
    std::unique_ptr<Expression> left, right;
};

struct Assignment {
    std::string name;
    Type type;
    std::unique_ptr<Expression> expr;
};

struct Print {
    std::unique_ptr<Expression> expr;
};

struct Block {
    std::vector<Statement> statements;
};

struct If {
    std::unique_ptr<Expression> condition;
    Block body;
};

struct While {
    std::unique_ptr<Expression> condition;
    Block body;
};

void print_statement(const Statement& stmt, int indent = 0);
void print_expression(const Expression& expr, int indent = 0);
