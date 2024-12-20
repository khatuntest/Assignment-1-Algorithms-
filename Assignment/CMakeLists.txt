cmake_minimum_required(VERSION 3.27)
project(Assignment)

set(CMAKE_CXX_STANDARD 17)

add_executable(Hash MainHash.cpp  Hashing.cpp Hashing.h OpenAddressingHashTable.cpp  OpenAddressingHashTable.h)
add_executable(skip   MainSkipList.cpp SkipList.cpp SkipList.h)
add_executable(Game Game.cpp SkipList.h SkipList.cpp)
add_executable(RBTree RedBlackTree.cpp)
add_executable(chain Chain.cpp Hashing.cpp Hashing.h )
