cmake_minimum_required(VERSION 3.6)
project(data_structure_and_algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES chapter2/fib.c chapter2/fib.h chapter2/binary_search.c chapter2/binary_search.h chapter2/MaxSubsequenceSum.c chapter2/MaxSubsequenceSum.h chapter2/main.c chapter2/util.c chapter2/util.h)
add_executable(data_structure_and_algorithm ${SOURCE_FILES})