cmake_minimum_required(VERSION 3.6)
project(ArrayVectorTester)

set(CMAKE_C_STANDARD 99)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

set(SOURCE_FILES main.c)
add_executable(ArrayVectorTester ${SOURCE_FILES})

include(FindPkgConfig)
find_package(LibDS REQUIRED)
include_directories(${LIBDS_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${LIBDS_LIBRARY})