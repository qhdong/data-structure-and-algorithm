cmake_minimum_required(VERSION 3.6)
project(data_structure_and_algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES chapter2/fib.c chapter2/fib.h chapter2/binary_search.c chapter2/binary_search.h chapter2/MaxSubsequenceSum.c chapter2/MaxSubsequenceSum.h chapter2/main.c chapter2/util.c chapter2/util.h chapter2/gcd.c chapter2/gcd.h chapter2/pow.c chapter2/pow.h chapter2/permutation.c chapter2/permutation.h chapter2/horner.c chapter2/horner.h chapter2/prime.c chapter2/prime.h)
add_executable(data_structure_and_algorithm ${SOURCE_FILES})