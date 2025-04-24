# sync_logger_test
add_executable(sync_logger_test
    src/sync_logger_test.cpp
)

target_include_directories(sync_logger_test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(sync_logger_test PRIVATE logger third-party)
