cmake_minimum_required(VERSION 3.6)
project(BalancedBST)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c BalancedBST.c BalancedBST.h)
add_executable(BalancedBST ${SOURCE_FILES} BalancedBST.c BalancedBST.h)