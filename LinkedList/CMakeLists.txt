cmake_minimum_required(VERSION 3.6)
project(LinkedList)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c LinkedList.cpp LinkedList.h)
add_executable(LinkedList ${SOURCE_FILES})