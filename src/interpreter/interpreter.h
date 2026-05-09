#pragma once

#include "../Module_1/natural.h"
#include "../Module_2/integer.h"
#include "../Module_3/rational.h"
#include "../Module_4/part0.h"
#include "ast.h"

#include <string>
#include <unordered_map>
#include <variant>

using Result = std::variant<big_N, big_Z, big_Q, big_P>;

class Interpreter {
  public:
    Result evaluate_expression(const Expression& expr);
  private:
    std::unordered_map<std::string, big_N> context_ints;
    std::unordered_map<std::string, big_Z> context_nats;
    std::unordered_map<std::string, big_Q> context_rats;
    std::unordered_map<std::string, big_P> context_polys;
};
