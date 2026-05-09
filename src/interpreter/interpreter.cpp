#include "interpreter.h"
#include "ast.h"
#include <stdexcept>
#include <variant>

template <class... Ts> struct overloaded: Ts... {
    using Ts::operator()...;
};
template <class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

// geniunenly might be the worst code i've ever written in my life
// clang-format off
Result Interpreter::evaluate_expression(const Expression& expr) {
    return std::visit(overloaded
    {
        [](const Number& n) -> Result { return n.value; },
        [&](const Variable& v) -> Result {
            if (context_nats.contains(v.name))
                return context_nats[v.name];
            if (context_ints.contains(v.name))
                return context_ints[v.name];
            if (context_rats.contains(v.name))
                return context_nats[v.name];
            if (context_polys.contains(v.name))
                return context_polys[v.name];

            throw std::runtime_error("Variable " + v.name + " not found");
        },


        // literal insanity
        [&](const BinaryOp& op) -> Result {
            Result left = evaluate_expression(*op.left);
            Result right = evaluate_expression(*op.right);
            return std::visit(overloaded
            {
                [&](const big_N& n) -> Result {
                    return std::visit(overloaded
                    {
                        [&](const big_N& other_n) -> Result {
                            if (op.op == "+")
                                return ADD_NN_N(n, other_n);
                            if (op.op == "-")
                                return SUB_ZZ_Z(TRANS_N_Z(n), TRANS_N_Z(other_n));
                            if (op.op == "*")
                                return MUL_NN_N(n, other_n);
                            if (op.op == "/")
                                return DIV_QQ_Q(
                                    TRANS_Z_Q(TRANS_N_Z(n)),
                                    TRANS_Z_Q(TRANS_N_Z(other_n))
                                );
                            throw std::runtime_error("Unknown operator encountered during evaluation");
                        },
                        [&](const big_Z& other_z) -> Result {
                            if (op.op == "+")
                                return ADD_ZZ_Z(TRANS_N_Z(n), other_z);
                            if (op.op == "-")
                                return SUB_ZZ_Z(TRANS_N_Z(n), other_z);
                            if (op.op == "*")
                                return MUL_ZZ_Z(TRANS_N_Z(n), other_z);
                            if (op.op == "/")
                                return DIV_QQ_Q(
                                    TRANS_Z_Q(TRANS_N_Z(n)),
                                    TRANS_Z_Q(other_z)
                                );
                            throw std::runtime_error("Unknown operator encountered during evaluation");
                        },
                        [&](const big_Q& other_q) -> Result {
                            if (op.op == "+")
                                return ADD_QQ_Q(TRANS_Z_Q(TRANS_N_Z(n)), other_q);
                            if (op.op == "-")
                                return SUB_QQ_Q(TRANS_Z_Q(TRANS_N_Z(n)), other_q);
                            if (op.op == "*")
                                return MUL_QQ_Q(TRANS_Z_Q(TRANS_N_Z(n)), other_q);
                            if (op.op == "/")
                                return DIV_QQ_Q(
                                    TRANS_Z_Q(TRANS_N_Z(n)),
                                    other_q
                                );
                            throw std::runtime_error("Unknown operator encountered during evaluation");
                        },
                        [&](const big_P& other_p) -> Result {
                            // TODO
                            return n;
                            throw std::runtime_error("Unknown operator encountered during evaluation");
                        }
                    }, right);
                },
                [&](const big_Z& z) -> Result { return z; },
                [&](const big_Q& q) -> Result { return q; },
                [&](const big_P& p) -> Result { return p; },
            }, left);
        },
    }, expr);
}
// clang-format on
