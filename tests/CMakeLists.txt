SET(catch2_dir ${CMAKE_CURRENT_SOURCE_DIR}/lib/Catch2)
add_subdirectory(${catch2_dir})
list(APPEND CMAKE_MODULE_PATH "${catch2_dir}/contrib/")

add_executable(tests test.cpp)
target_include_directories(tests PUBLIC "${catch2_dir}/single_include/catch2/")
target_link_libraries(tests FeatherFifo)

include(CTest)
include(Catch)
catch_discover_tests(tests)