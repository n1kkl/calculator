cmake_minimum_required(VERSION 3.30)
project(string_calculator)

set(CMAKE_CXX_STANDARD 23)

# dependencies
Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.8.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(string_calculator main.cpp
        lexer.h
        lexer.cpp
        token.h
        token.cpp)

add_executable(tests lexer.test.cpp
        lexer.h
        lexer.cpp
        token.h
        token.cpp)
target_link_libraries(tests Catch2::Catch2WithMain)