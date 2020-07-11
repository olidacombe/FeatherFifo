cmake_minimum_required(VERSION 3.17)

project(FeatherFifo VERSION 0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(lib/Catch2)
add_executable(tests test.cpp)
target_link_libraries(tests Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(tests)