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
FetchContent_Declare(
        magic_enum
        GIT_REPOSITORY https://github.com/Neargye/magic_enum.git
        GIT_TAG v0.9.7
)

FetchContent_MakeAvailable(Catch2)
FetchContent_MakeAvailable(magic_enum)

add_executable(string_calculator main.cpp
        lexer.h
        lexer.cpp
        token.h
        token.cpp)
target_link_libraries(string_calculator magic_enum)

add_executable(tests lexer.test.cpp
        lexer.h
        lexer.cpp
        token.h
        token.cpp)
target_link_libraries(tests Catch2::Catch2WithMain)
