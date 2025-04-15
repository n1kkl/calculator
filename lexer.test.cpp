#include <catch2/catch_test_macros.hpp>

#include "lexer.h"

TEST_CASE( "next token returns correct token", "[lexer]" ) {
    Lexer lexer("11+2  - 3ab3/ 4*(  555)");
    Token tests[14] = {
        Token(TokenType::Number, "11"),
        Token(TokenType::Add, "+"),
        Token(TokenType::Number, "2"),
        Token(TokenType::Sub, "-"),
        Token(TokenType::Number, "3"),
        Token(TokenType::Illegal, "a"),
        Token(TokenType::Illegal, "b"),
        Token(TokenType::Number, "3"),
        Token(TokenType::Div, "/"),
        Token(TokenType::Number, "4"),
        Token(TokenType::Mul, "*"),
        Token(TokenType::LParen, "("),
        Token(TokenType::Number, "555"),
        Token(TokenType::RParen, ")"),
    };

    for (Token test: tests) {
        Token next_token = lexer.next_token();

        REQUIRE(test.literal == next_token.literal);
        REQUIRE(test.type == next_token.type);
    }
}