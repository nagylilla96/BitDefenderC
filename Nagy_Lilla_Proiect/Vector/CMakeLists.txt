cmake_minimum_required(VERSION 3.6)
project(Vector)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c Vector.c Vector.h)
add_executable(Vector ${SOURCE_FILES} main.c)