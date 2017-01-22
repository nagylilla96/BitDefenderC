cmake_minimum_required(VERSION 3.6)
project(BalancedBSTTester)

set(CMAKE_C_STANDARD 99)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

set(SOURCE_FILES main.c BalancedBSTTester.c BalancedBSTTester.h)
add_executable(BalancedBSTTester ${SOURCE_FILES} BalancedBSTTester.c BalancedBSTTester.h)

include(FindPkgConfig)
find_package(LibDS REQUIRED)
include_directories(${LIBDS_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${LIBDS_LIBRARY})