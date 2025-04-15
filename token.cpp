#include <string>
#include <iostream>
#include <magic_enum/magic_enum.hpp>
#include "token.h"

Token::Token(const TokenType type, std::string value) : type(type), literal(std::move(value)) {}

std::ostream& operator<<(std::ostream &strm, const Token &token) {
    return strm << magic_enum::enum_name(token.type) << "(" << token.literal << ")";
}
