#ifndef LEXER_H
#define LEXER_H

#include <memory>
#include "token.h"

class Lexer {
public:
    explicit Lexer(std::string input);
    void read_char();
    Token next_token();
private:
    std::string input;
    int position = 0;
    int read_position = 0;
    char current_char;

    static bool is_whitespace(char token);
    void skip_whitespace();

    static bool is_number(char token);
    std::string read_number();
};

#endif
