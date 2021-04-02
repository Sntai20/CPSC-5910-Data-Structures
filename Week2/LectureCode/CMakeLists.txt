cmake_minimum_required(VERSION 3.17)
project(LectureCode)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Werror -pedantic")

add_executable(factorial factorial.cpp)
add_executable(writebackwards writebackwards.cpp)
add_executable(maxarray maxarray.cpp)
add_executable(binarysearch binarysearch.cpp)
add_executable(templatefunction templatefunction.cpp)