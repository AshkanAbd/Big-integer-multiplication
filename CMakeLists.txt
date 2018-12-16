cmake_minimum_required(VERSION 3.0)
project(Big-Integer-Multiplication C)

set(CMAKE_C_STANDARD 99)

add_executable(Big-Integer-Multiplication main.c)

target_link_libraries(Big-Integer-Multiplication m)
