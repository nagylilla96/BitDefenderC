cmake_minimum_required(VERSION 3.6)
project(HashTable)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c HashTable.c HashTable.h LinkedList.h LinkedList.c)
add_executable(HashTable ${SOURCE_FILES} HashTable.c HashTable.h LinkedList.c LinkedList.h)
target_link_libraries(HashTable m)