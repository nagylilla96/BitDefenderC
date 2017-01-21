cmake_minimum_required(VERSION 3.6)
project(BST)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c BST.c BST.h)
add_executable(BST ${SOURCE_FILES} BST.c BST.h)