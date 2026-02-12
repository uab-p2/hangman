cmake_minimum_required(VERSION 3.10)
project(hangman)
set(CMAKE_CXX_STANDARD 20)

add_executable(hangman)
file(GLOB_RECURSE files
    src/*.h
    src/*.hpp
    src/*.cpp)
target_sources(hangman PRIVATE ${files})

# Show some extra warning and include extra debug info
target_compile_options(hangman PRIVATE
        $<$<CXX_COMPILER_ID:GNU,Clang>:-Wextra -O0 -g3>
        $<$<CXX_COMPILER_ID:MSVC>:/W4 /Od /Zi>
)