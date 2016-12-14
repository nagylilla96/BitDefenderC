cmake_minimum_required(VERSION 3.6)
project(l06e12)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES cmake-build-debug/main.c cmake-build-debug/e12.c cmake-build-debug/e12.h)
add_executable(l06e12 ${SOURCE_FILES})