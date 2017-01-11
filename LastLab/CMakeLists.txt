cmake_minimum_required(VERSION 3.6)
project(LastLab)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c lastLab.c lastLab.h)
add_executable(LastLab ${SOURCE_FILES} lastLab.c lastLab.h)