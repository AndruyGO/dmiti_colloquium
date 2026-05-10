#include "interpreter.h"
#include "ast.h"
#include "../Module_2/part1.h"
#include "../Module_2/part2.h"
#include "../Module_2/part3.h"
#include "../Module_2/part4.h"
#include "../Module_4/part1.h"
#include "../Module_4/part2.h"
#include "../Module_4/part3.h"
#include "../Module_4/part4.h"

#include <stdexcept>
#include <variant>

template <class... Ts> struct overloaded: Ts... {
    using Ts::operator()...;
};
template <class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

Interpreter::Interpreter() {
    big_P x;
    x.monomials.push_back(monomial(big_N {"1"}, big_Q {"1"}));
    context_polys["x"] = x;
}

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
                // NATURAL
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
                            monomial mon(big_N{"0"}, TRANS_Z_Q(TRANS_N_Z(n)));
                            big_P p {};
                            p.monomials.push_back(mon);
                            
                            if (op.op == "+")
                                return ADD_PP_P(p, other_p);
                            if (op.op == "-")
                                return SUB_PP_P(p, other_p);
                            if (op.op == "*")
                                return MUL_PP_P(p, other_p);
                            if (op.op == "/")
                                return DIV_PP_P(p, other_p);
                            throw std::runtime_error("Unknown operator encountered during evaluation");
                        }
                    }, right);
                },
                // INTEGER
                [&](const big_Z& z) -> Result {
                    return std::visit(overloaded
                    {
                        [&](const big_N& other_n) -> Result {
                            if (op.op == "+")
                                return ADD_ZZ_Z(z, TRANS_N_Z(other_n));
                            if (op.op == "-")
                                return SUB_ZZ_Z(z, TRANS_N_Z(other_n));
                            if (op.op == "*")
                                return MUL_ZZ_Z(z, TRANS_N_Z(other_n));
                            if (op.op == "/")
                                return DIV_QQ_Q(
                                    TRANS_Z_Q(z),
                                    TRANS_Z_Q(TRANS_N_Z(other_n))
                                );
                            throw std::runtime_error("Unknown operator encountered during evaluation");
                        },
                        [&](const big_Z& other_z) -> Result {
                            if (op.op == "+")
                                return ADD_ZZ_Z(z, other_z);
                            if (op.op == "-")
                                return SUB_ZZ_Z(z, other_z);
                            if (op.op == "*")
                                return MUL_ZZ_Z(z, other_z);
                            if (op.op == "/")
                                return DIV_QQ_Q(
                                    TRANS_Z_Q(z),
                                    TRANS_Z_Q(other_z)
                                );
                            throw std::runtime_error("Unknown operator encountered during evaluation");
                        },
                        [&](const big_Q& other_q) -> Result {
                            if (op.op == "+")
                                return ADD_QQ_Q(TRANS_Z_Q(z), other_q);
                            if (op.op == "-")
                                return SUB_QQ_Q(TRANS_Z_Q(z), other_q);
                            if (op.op == "*")
                                return MUL_QQ_Q(TRANS_Z_Q(z), other_q);
                            if (op.op == "/")
                                return DIV_QQ_Q(
                                    TRANS_Z_Q(z),
                                    other_q
                                );
                            throw std::runtime_error("Unknown operator encountered during evaluation");
                        },
                        [&](const big_P& other_p) -> Result {
                            monomial mon(big_N{"0"}, TRANS_Z_Q(z));
                            big_P p{};
                            p.monomials.push_back(mon);
                            
                            if (op.op == "+")
                                return ADD_PP_P(p, other_p);
                            if (op.op == "-")
                                return SUB_PP_P(p, other_p);
                            if (op.op == "*")
                                return MUL_PP_P(p, other_p);
                            if (op.op == "/")
                                return DIV_PP_P(p, other_p);
                            throw std::runtime_error("Unknown operator encountered during evaluation");
                        }
                    }, right);
                },
                // RATIONAL
                [&](const big_Q& q) -> Result {
                    return std::visit(overloaded
                    {
                        [&](const big_N& other_n) -> Result {
                            if (op.op == "+")
                                return ADD_QQ_Q(q, TRANS_Z_Q(TRANS_N_Z(other_n)));
                            if (op.op == "-")
                                return SUB_QQ_Q(q, TRANS_Z_Q(TRANS_N_Z(other_n)));
                            if (op.op == "*")
                                return SUB_QQ_Q(q, TRANS_Z_Q(TRANS_N_Z(other_n)));
                            if (op.op == "/")
                                return DIV_QQ_Q(
                                    q,
                                    TRANS_Z_Q(TRANS_N_Z(other_n))
                                );
                            throw std::runtime_error("Unknown operator encountered during evaluation");
                        },
                        [&](const big_Z& other_z) -> Result {
                            if (op.op == "+")
                                return ADD_QQ_Q(q, TRANS_Z_Q(other_z));
                            if (op.op == "-")
                                return SUB_QQ_Q(q, TRANS_Z_Q(other_z));
                            if (op.op == "*")
                                return MUL_QQ_Q(q, TRANS_Z_Q(other_z));
                            if (op.op == "/")
                                return DIV_QQ_Q(
                                    q,
                                    TRANS_Z_Q(other_z)
                                );
                            throw std::runtime_error("Unknown operator encountered during evaluation");
                        },
                        [&](const big_Q& other_q) -> Result {
                            if (op.op == "+")
                                return ADD_QQ_Q(q, other_q);
                            if (op.op == "-")
                                return SUB_QQ_Q(q, other_q);
                            if (op.op == "*")
                                return MUL_QQ_Q(q, other_q);
                            if (op.op == "/")
                                return DIV_QQ_Q(q, other_q);
                            throw std::runtime_error("Unknown operator encountered during evaluation");
                        },
                        [&](const big_P& other_p) -> Result {
                            monomial mon(big_N{"0"}, q);
                            big_P p {};
                            p.monomials.push_back(mon);
                            
                            if (op.op == "+")
                                return ADD_PP_P(p, other_p);
                            if (op.op == "-")
                                return SUB_PP_P(p, other_p);
                            if (op.op == "*")
                                return MUL_PP_P(p, other_p);
                            if (op.op == "/")
                                return DIV_PP_P(p, other_p);
                            throw std::runtime_error("Unknown operator encountered during evaluation");
                        }
                    }, right);
                },
                // POLYNOMIAL
                [&](const big_P& p) -> Result {
                    return std::visit(overloaded
                    {
                        [&](const big_N& other_n) -> Result {
                            monomial mon(big_N{"0"}, TRANS_Z_Q(TRANS_N_Z(other_n)));
                            big_P other_p {};
                            other_p.monomials.push_back(mon);
                            
                            if (op.op == "+")
                                return ADD_PP_P(p, other_p);
                            if (op.op == "-")
                                return SUB_PP_P(p, other_p);
                            if (op.op == "*")
                                return MUL_PP_P(p, other_p);
                            if (op.op == "/")
                                return DIV_PP_P(p, other_p);
                            throw std::runtime_error("Unknown operator encountered during evaluation");
                        },
                        [&](const big_Z& other_z) -> Result {
                            monomial mon(big_N{"0"}, TRANS_Z_Q(other_z));
                            big_P other_p {};
                            other_p.monomials.push_back(mon);
                            
                            if (op.op == "+")
                                return ADD_PP_P(p, other_p);
                            if (op.op == "-")
                                return SUB_PP_P(p, other_p);
                            if (op.op == "*")
                                return MUL_PP_P(p, other_p);
                            if (op.op == "/")
                                return DIV_PP_P(p, other_p);
                            throw std::runtime_error("Unknown operator encountered during evaluation");
                        },
                        [&](const big_Q& other_q) -> Result {
                            monomial mon(big_N{"0"}, other_q);
                            big_P other_p {};
                            other_p.monomials.push_back(mon);
                            
                            if (op.op == "+")
                                return ADD_PP_P(p, other_p);
                            if (op.op == "-")
                                return SUB_PP_P(p, other_p);
                            if (op.op == "*")
                                return MUL_PP_P(p, other_p);
                            if (op.op == "/")
                                return DIV_PP_P(p, other_p);
                            throw std::runtime_error("Unknown operator encountered during evaluation");
                        },
                        [&](const big_P& other_p) -> Result {
                            if (op.op == "+")
                                return ADD_PP_P(p, other_p);
                            if (op.op == "-")
                                return SUB_PP_P(p, other_p);
                            if (op.op == "*")
                                return MUL_PP_P(p, other_p);
                            if (op.op == "/")
                                return DIV_PP_P(p, other_p);
                            throw std::runtime_error("Unknown operator encountered during evaluation");
                        }
                    }, right);
                },
            }, left);
        },
    }, expr);
}

std::ostream& operator<<(std::ostream& os, const Result& obj) {
    std::visit(overloaded
    {
        [&](const big_N& n) {os << n;},
        [&](const big_Z& n) {os << n;},
        [&](const big_Q& n) {os << n;},
        [&](const big_P& n) {os << n;},
    }, obj);
};

void Interpreter::execute_statement(const Statement& stmt) {
    std::visit(overloaded
    {
        [&](const Assignment& st) {
            Result value = evaluate_expression(*st.expr);
            if (st.type == Type::Infer)
                std::cout << value << "\n";
            else {
                std::visit(overloaded
                {
                    [&](const big_N& n) {context_nats[st.name] = n;},
                    [&](const big_Z& z) {context_ints[st.name] = z;},
                    [&](const big_Q& q) {context_rats[st.name] = q;},
                    [&](const big_P& p) {context_polys[st.name] = p;},
                }, value);
            }
        },
        [&](const Print& st) {
            Result value = evaluate_expression(*st.expr);
            std::cout << value << "\n";
        },
        [&](const If& st) {
            // TODO
        },
        [&](const While& st) {
            // TODO
        },
        [&](const Block& st) {
            // TODO
        },
    }, stmt);
}
// clang-format on
