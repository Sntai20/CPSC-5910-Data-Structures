cmake_minimum_required(VERSION 3.19)
project(Lecture)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Werror -pedantic")

add_executable(Lecture main.cpp ArrayMaxHeap.h)
add_executable(ComplexTester complextester.cpp)