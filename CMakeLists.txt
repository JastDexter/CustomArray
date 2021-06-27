cmake_minimum_required(VERSION 3.17)
project(CustomArray)

set(CMAKE_CXX_STANDARD 98)

add_executable(CustomArray main.cpp CustomTemplatedArray.h CustomTemplatedArray.tpp)