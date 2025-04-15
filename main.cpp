#include <chrono>
#include <iostream>

#include "lexer.h"

[[noreturn]] int main() {
    while (true) {
        std::cout << ">>  ";
        std::string line;
        std::getline(std::cin, line);

        auto start = std::chrono::high_resolution_clock::now();

        Lexer lexer(line);
        std::vector<Token> tokens = std::vector<Token>();

        for (Token token = lexer.next_token(); token.type != TokenType::End; token = lexer.next_token()) {
            tokens.push_back(token);
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        std::cout << "";
        for (const Token& token: tokens) {
            std::cout << token << " ";
        }
        std::cout << std::endl;

        std::cout << "lexing time: " << microseconds << std::endl;
    }
}
