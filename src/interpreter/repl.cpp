#include "repl.h"
#include "ast.h"
#include "lexer.h"
#include "parser.h"

#include <iostream>
#include <string>
#include <vector>

void start_repl() {
    std::string line;
    std::cout << ">>> ";
    while (std::getline(std::cin, line)) {
        if (line == ":q" || line == ":quit")
            break;
        try {
            Lexer lexer(line);
            const std::vector<Token> tokens = lexer.tokenize();
            for (const auto& token : tokens) {
                std::cout << token << "\n";
            }

            Parser parser(tokens);
            const std::vector<Statement> stmts = parser.parse();

            for (const auto& stmt : stmts) {
                print_statement(stmt);
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
        std::cout << "\n>>> ";
    }
}
