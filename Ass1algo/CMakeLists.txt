cmake_minimum_required(VERSION 3.27)
project(Ass1algo)

set(CMAKE_CXX_STANDARD 17)

add_executable(fib main.cpp Fibonacci.cpp Fibonacci.h)
add_executable(search SearchMain.cpp SearchTypes.cpp SearchTypes.h)
add_executable(heap HeapMain.cpp heap.cpp heap.h)
add_executable(queue QueueMain.cpp Priority_queue.cpp Priority_queue.h)
