#include <iostream>

#include "lexer.h"

[[noreturn]] int main() {
    while (true) {
        std::cout << ">> ";
        std::string line;
        std::getline(std::cin, line);
        Lexer lexer(line);

        std::cout << "";
        for (Token token = lexer.next_token(); token.type != TokenType::End; token = lexer.next_token()) {
            std::cout << token << " ";
        }
        std::cout << std::endl;
    }
}
