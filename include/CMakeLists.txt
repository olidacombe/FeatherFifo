configure_file(config.hpp.in config.hpp)

target_include_directories(FeatherFifo PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )