cmake_minimum_required(VERSION 3.17)

project(FeatherFifo VERSION 0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(tests test.cpp)