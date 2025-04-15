#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum class TokenType {
    Number = 1,

    // special
    Illegal = 2,
    End = 3,

    // operators
    Add = 4,
    Sub = 5,
    Mul = 6,
    Div = 7,

    // delimiters
    LParen = 8,
    RParen = 9
};

struct Token {
    TokenType type;
    std::string literal;
    Token(TokenType type, std::string value);
};

std::ostream& operator<<(std::ostream &strm, const Token &token);

#endif