cmake_minimum_required(VERSION 3.14)
project(lab06)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab06
        dynamicarray.cpp
        dynamicarray.h
        main.cpp)
