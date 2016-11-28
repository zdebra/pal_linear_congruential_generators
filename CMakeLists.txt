cmake_minimum_required(VERSION 3.6)
project(pal_linear_congruential_generators)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(pal_linear_congruential_generators ${SOURCE_FILES})