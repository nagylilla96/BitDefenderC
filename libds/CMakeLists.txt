cmake_minimum_required(VERSION 3.6)
project(libds)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES Vector.c Vector.h)
add_library(libds ${SOURCE_FILES})