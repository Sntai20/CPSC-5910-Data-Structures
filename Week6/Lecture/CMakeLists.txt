cmake_minimum_required(VERSION 3.19)
project(Lecture)

set(CMAKE_CXX_STANDARD 11)

add_executable(Lecture main.cpp)
add_executable(one Inheritance/01_baseballplayer.cpp)
add_executable(two Inheritance/02_employee.cpp)
add_executable(three Inheritance/03_baseballplayer.cpp)
add_executable(four Inheritance/04_derived.cpp)
add_executable(five Inheritance/05_derived.cpp)
add_executable(six Inheritance/06_orderchain.cpp)
add_executable(seven Inheritance/07_orderchain.cpp)
add_executable(eight Inheritance/08_derived.cpp)
add_executable(nine Inheritance/09_rectangle.cpp)
add_executable(ten Inheritance/10_shape.cpp)
add_executable(eleven Inheritance/11_slicing.cpp)

add_executable(poly Polymorphism/08_polygon.cpp)
