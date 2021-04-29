cmake_minimum_required(VERSION 3.19)
project(CPP)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Werror -pedantic")

add_executable(SmartPtrDemo main.cpp SmartPtr.h)
add_executable(TimerTest Solution/timertest.cpp Solution/Timer.h Solution/Timer.h)