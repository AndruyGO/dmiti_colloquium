#include "repl.h"
#include "ast.h"
#include "interpreter.h"
#include "lexer.h"
#include "parser.h"

#include <iostream>
#include <string>
#include <vector>

void start_repl() {
    Interpreter intpr;
    std::string line;
    std::cout << ">>> ";
    while (std::getline(std::cin, line)) {
        if (line == ":q" || line == ":quit")
            break;
        try {
            Lexer lexer(line);
            const std::vector<Token> tokens = lexer.tokenize();

            Parser parser(tokens);
            const std::vector<Statement> stmts = parser.parse();

            for (const auto& stmt : stmts) {
                intpr.execute_statement(stmt);
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
        std::cout << "\n>>> ";
    }
}
