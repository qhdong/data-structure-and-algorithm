cmake_minimum_required(VERSION 3.6)
project(data_structure_and_algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(SOURCE_FILES chapter2/fib.c chapter2/fib.h chapter2/binary_search.c chapter2/binary_search.h chapter2/MaxSubsequenceSum.c chapter2/MaxSubsequenceSum.h chapter2/main.c chapter2/util.c chapter2/util.h chapter2/gcd.c chapter2/gcd.h chapter2/pow.c chapter2/pow.h chapter2/permutation.c chapter2/permutation.h chapter2/horner.c chapter2/horner.h chapter2/prime.c chapter2/prime.h chapter3/linkedlist.c chapter3/linkedlist.h)
#add_executable(data_structure_and_algorithm ${SOURCE_FILES})
#set(SOURCE_FILES chapter3/main.c chapter3/polynomial.c chapter3/polynomial.h chapter3/util.c chapter3/util.h chapter3/cursor.c chapter3/cursor.h chapter3/linkedstack.c chapter3/linkedstack.h)
#add_executable(data_structure_and_algorithm ${SOURCE_FILES})

#set(SOURCE_FILES chapter3/main.c  chapter3/arrayqueue.c chapter3/arrayqueue.h chapter3/exercise.c)
#set(SOURCE_FILES chapter3/linkedlist.h chapter3/linkedlist.c chapter3/exercise.c chapter3/joesphus.c)
#set(SOURCE_FILES chapter3/joesphus.c chapter3/testLinkedList.c)

#set(SOURCE_FILES chapter4/searchtree.c chapter4/searchtree.h chapter4/testSearchTree.c)
#set(SOURCE_FILES chapter4/avltree.c chapter4/avltree.h chapter4/testAVLTree.c chapter5/hashmap.c chapter5/hashmap.h)
#set(SOURCE_FILES chapter5/hashtable.c chapter5/hashtable.h chapter5/prime.c chapter5/prime.h chapter5/testhashmap.c chapter5/hashtable_quad.c chapter5/hashtable_quad.h)
set(SOURCE_FILES chapter5/prime.c chapter5/prime.h chapter5/hashtable_quad.c chapter5/hashtable_quad.h chapter5/test_hash_quad.c)
add_executable(data_structure_and_algorithm ${SOURCE_FILES})