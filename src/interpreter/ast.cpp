#include "ast.h"

#include <string>

template <class... Ts> struct overloaded: Ts... {
    using Ts::operator()...;
};
template <class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

constexpr std::string_view getTypeName(Type type) {
    switch (type) {
    case Type::Nat:
        return "Nat";
    case Type::Int:
        return "Int";
    case Type::Rat:
        return "Rat";
    case Type::Poly:
        return "Poly";
    case Type::Infer:
        return "Infer";
    default:
        return "Unknown";
    }
}

void print_statement(const Statement& stmt, int indent) {
    std::visit(overloaded {
                   [indent](const Print& st) {
                       std::cout << std::string(indent, ' ') << "Print(\n";
                       print_expression(*st.expr, indent + 2);
                       std::cout << std::string(indent, ' ') << ")\n";
                   },
                   [indent](const If& st) { std::cout << "TODO\n"; },
                   [indent](const While& st) { std::cout << "TODO\n"; },
                   [indent](const Block& st) { std::cout << "TODO\n"; },
                   [indent](const Assignment& st) {
                       std::cout << std::string(indent, ' ') << "Assignment("
                                 << getTypeName(st.type) << ", " << st.name
                                 << ") {\n";
                       print_expression(*st.expr, indent + 2);
                       std::cout << std::string(indent, ' ') << "}\n";
                   },
               },
        stmt);
}

void print_expression(const Expression& expr, int indent) {
    std::visit(overloaded {
                   [indent](const Number& ex) {
                       std::cout << std::string(indent, ' ') << "Number("
                                 << ex.value << ")\n";
                   },
                   [indent](const Variable& ex) {
                       std::cout << std::string(indent, ' ') << "Variable("
                                 << ex.name << ")\n";
                   },
                   [indent](const BinaryOp& ex) {
                       std::cout << std::string(indent, ' ') << "BinaryOp("
                                 << ex.op << ") {\n";
                       print_expression(*ex.left, indent + 2);
                       print_expression(*ex.right, indent + 2);
                       std::cout << std::string(indent, ' ') << ")\n";
                   },
                   [indent](const FuncCall& ex) {
                       std::cout << std::string(indent, ' ') << "FuncCall("
                                 << ex.name << ") {\n";
                       print_expression(*ex.argument, indent + 2);
                       std::cout << std::string(indent, ' ') << ")\n";
                   },
               },
        expr);
}
