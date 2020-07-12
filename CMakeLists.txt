cmake_minimum_required(VERSION 3.17)

project(FeatherFifo VERSION 0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(FeatherFifo FeatherFifo.cpp FeatherFifo.hpp)

SET(catch2_dir ${PROJECT_SOURCE_DIR}/lib/Catch2)
add_subdirectory(${catch2_dir})
list(APPEND CMAKE_MODULE_PATH "${catch2_dir}/contrib/")
add_executable(tests test.cpp)
target_include_directories(tests PUBLIC "${catch2_dir}/single_include/catch2/")
target_link_libraries(tests Catch2::Catch2 FeatherFifo)

include(CTest)
include(Catch)
catch_discover_tests(tests)