cmake_minimum_required(VERSION 3.10)
project(hangman)
set(CMAKE_CXX_STANDARD 20)

add_executable(hangman)
target_compile_options(hangman PRIVATE -Wextra -O0 -g3)
file(GLOB_RECURSE files
    src/*.h
    src/*.hpp
    src/*.cpp)
target_sources(hangman PRIVATE ${files})
