cmake_minimum_required(VERSION 3.6)
project(Lab08Ex03)

set(CMAKE_C_STANDARD 99)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

set(SOURCE_FILES main.c lab8e3.h lab8e3.c)
add_executable(Lab08Ex03 ${SOURCE_FILES} lab8e3.h lab8e3.c)
include(FindPkgConfig)
find_package(LibDS REQUIRED)
include_directories(${LIBDS_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${LIBDS_LIBRARY})