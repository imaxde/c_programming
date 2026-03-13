cmake_minimum_required(VERSION 3.25)
project(hello C)
add_executable(main hello.c)
target_compile_options(main PRIVATE -Wall -Wextra)