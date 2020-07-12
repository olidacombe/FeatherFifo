cmake_minimum_required(VERSION 3.17)

project(FeatherFifo VERSION 0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(FeatherFifo FeatherFifo.cpp FeatherFifo.hpp)
target_include_directories (FeatherFifo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(tests)
