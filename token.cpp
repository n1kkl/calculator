#include <string>
#include <iostream>
#include "token.h"

Token::Token(const TokenType type, std::string value) : type(type), literal(std::move(value)) {}
