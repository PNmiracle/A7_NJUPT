cmake_minimum_required(VERSION 3.20)
project(A7_NJUPT)

set(CMAKE_CXX_STANDARD 14)

add_executable(A7_NJUPT function.h queue.cpp main.cpp)

add_executable(main hash_preTraverse/new_main.cpp)
add_executable(FileExer FileExer.cpp)