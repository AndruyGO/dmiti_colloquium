#include "../Module_1/natural.h"
#include "../Module_2/integer.h"
#include "../Module_3/rational.h"
#include "../Module_4/polynomial.h"

#include "interpreter.h"
#include "ast.h"

#include <algorithm>
#include <cctype>
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
            if (v.name.starts_with("x^") && std::all_of(v.name.begin()+2, v.name.end(), ::isdigit)) {
                return  big_P {v.name};
            }
            
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

        [&](const FuncCall& c) -> Result {
            Result value = evaluate_expression(*c.argument);
            return std::visit(overloaded
            {
                [&](const big_N& n) -> Result {
                    if (c.name == "SIGN")
                        return big_N{"1"}; 
                    if (c.name == "DEG")
                        return big_N{"0"};
                    if (c.name == "DER")
                        return big_N{"0"};
                    if (c.name == "NMR") {
                        big_P p {};
                        p.monomials.push_back(monomial(big_N("0"), TRANS_Z_Q(TRANS_N_Z(n))));                        
                        return NMR_P_P(p);
                    }
                    throw std::runtime_error("Unknown function " + c.name);
                },
                [&](const big_Z& z) -> Result {
                    if (c.name == "SIGN")
                        return big_Z {std::string{SGN_Z_D(z)}}; 
                    if (c.name == "DEG")
                        return big_N{"0"};
                    if (c.name == "DER")
                        return big_N{"0"};
                    if (c.name == "NMR") {
                        big_P p {};
                        p.monomials.push_back(monomial(big_N("0"), TRANS_Z_Q(z)));                        
                        return NMR_P_P(p);
                    }
                    throw std::runtime_error("Unknown function " + c.name);
                },
                [&](const big_Q& q) -> Result {
                    if (c.name == "SIGN") {
                        if (!NZER_N_B(q.up))
                            return big_Z {"0"};
                        if (q.sign == 1)
                            return big_Z {"1"};
                        if (q.sign == -1)
                            return big_Z {"-1"};
                    }
                    if (c.name == "DEG")
                        return big_N{"0"};
                    if (c.name == "DER")
                        return big_N{"0"};
                    if (c.name == "NMR") {
                        big_P p {};
                        p.monomials.push_back(monomial(big_N("0"), q));                        
                        return NMR_P_P(p);
                    }
                    throw std::runtime_error("Unknown function " + c.name);
                },
                [&](const big_P& p) -> Result {
                    if (c.name == "SIGN")
                        throw std::runtime_error("SIGN is not allowed on polynomials");
                    if (c.name == "DEG")
                        return DEG_P_N(p);
                    if (c.name == "DER")
                        return DER_P_P(p);
                    if (c.name == "NMR") {
                        return NMR_P_P(p);
                    }
                    throw std::runtime_error("Unknown function " + c.name);
                },
            }, value);
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
                            if (op.op == "//")
                                return DIV_NN_N(n, other_n);
                            if (op.op == "%")
                                return MOD_NN_N(n, other_n);
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
                            if (op.op == "//")
                                return DIV_ZZ_Z(TRANS_N_Z(n), other_z);
                            if (op.op == "%")
                                return MOD_ZZ_Z(TRANS_N_Z(n), other_z);
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
                            if (op.op == "//" || op.op == "%")
                                throw std::runtime_error("Modulo division not possible");
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
                            if (op.op == "//" || op.op == "%")
                                throw std::runtime_error("Modulo division not possible");
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
                            if (op.op == "//")
                                return DIV_ZZ_Z(z, TRANS_N_Z(other_n));
                            if (op.op == "%")
                                return MOD_ZZ_Z(z, TRANS_N_Z(other_n));
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
                            if (op.op == "//")
                                return DIV_ZZ_Z(z, other_z);
                            if (op.op == "%")
                                return MOD_ZZ_Z(z, other_z);
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
                            if (op.op == "//" || op.op == "%")
                                throw std::runtime_error("Modulo division not possible");
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
                            if (op.op == "//" || op.op == "%")
                                throw std::runtime_error("Modulo division not possible");
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
                            if (op.op == "//" || op.op == "%")
                                throw std::runtime_error("Modulo division not possible");
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
                            if (op.op == "//" || op.op == "%")
                                throw std::runtime_error("Modulo division not possible");
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
                            if (op.op == "//" || op.op == "%")
                                throw std::runtime_error("Modulo division not possible");
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
                            if (op.op == "//" || op.op == "%")
                                throw std::runtime_error("Modulo division not possible");
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
                            if (op.op == "//" || op.op == "%")
                                throw std::runtime_error("Modulo division not possible");
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
                            if (op.op == "//" || op.op == "%")
                                throw std::runtime_error("Modulo division not possible");
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
                            if (op.op == "//" || op.op == "%")
                                throw std::runtime_error("Modulo division not possible");
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
                            if (op.op == "//" || op.op == "%")
                                throw std::runtime_error("Modulo division not possible");
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
        [&](const big_Z& z) {os << z;},
        [&](const big_Q& q) {os << q;},
        [&](const big_P& p) {os << p;},
    }, obj);
    return os;
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
            std::cout << "Nothing\n";
        },
        [&](const While& st) {
            // TODO
            std::cout << "Nothing\n";
        },
        [&](const Block& st) {
            // TODO
            std::cout << "Nothing\n";
        },
    }, stmt);
}
// clang-format on
