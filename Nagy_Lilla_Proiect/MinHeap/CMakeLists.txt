cmake_minimum_required(VERSION 3.6)
project(MinHeap)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c Vector.h Vector.c MinHeap.c MinHeap.h)
add_executable(MinHeap ${SOURCE_FILES} MinHeap.c MinHeap.h)