#include <utility>
#include "lexer.h"

Lexer::Lexer(std::string input) : input(std::move(input)) {
    current_char = 0;
    read_char();
}

void Lexer::read_char() {
    if (read_position >= input.length()) {
        current_char = 0;
    } else {
        current_char = input[read_position];
    }
    position = read_position;
    read_position += 1;
}

Token Lexer::next_token() {
    skip_whitespace();
    Token token(TokenType::Illegal, std::string(1, current_char));

    switch (current_char) {
        case '+':
            token = Token(TokenType::Add, "+");
            break;
        case '-':
            token = Token(TokenType::Sub, "-");
            break;
        case '*':
            token = Token(TokenType::Mul, "*");
            break;
        case '/':
            token = Token(TokenType::Div, "/");
            break;
        case '(':
            token = Token(TokenType::LParen, "(");
            break;
        case ')':
            token = Token(TokenType::RParen, ")");
            break;
        case 0:
            token = Token(TokenType::End, "");
            break;
        default:
            if (is_number(current_char)) {
                token = Token(TokenType::Number, read_number());
                return token;
            }
            break;
    }

    read_char();

    return token;
}

bool Lexer::is_whitespace(const char token) {
    return token == ' ' || token == '\t' || token == '\n' || token == '\r';
}

void Lexer::skip_whitespace() {
    while (is_whitespace(current_char)) {
        read_char();
    }
}

bool Lexer::is_number(const char token) {
    return token >= '0' && token <= '9';
}

std::string Lexer::read_number() {
    int from_position = position;
    while (is_number(current_char)) {
        read_char();
    }
    return input.substr(from_position, position - from_position);
}
