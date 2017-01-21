cmake_minimum_required(VERSION 3.6)
project(libds)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES Vector.c Vector.h LinkedList.c LinkedList.h HashTable.c HashTable.h MinHeap.c MinHeap.h BST.c BST.h)
add_library(libds ${SOURCE_FILES})