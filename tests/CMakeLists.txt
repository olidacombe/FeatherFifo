add_executable(test test.cpp ${PROJECT_SOURCE_DIR}/include/FeatherFifo.hpp)
target_include_directories(test PRIVATE ${PROJECT_SOURCE_DIR}/include/)
