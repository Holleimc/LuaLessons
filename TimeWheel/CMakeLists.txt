cmake_minimum_required(VERSION 3.0)
project(timewheel)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")


add_subdirectory(./timewheel)

add_subdirectory(./src)

