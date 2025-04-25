# sync_logger_test
add_executable(sync_logger_test
    src/sync_logger_test.cpp
)

target_include_directories(sync_logger_test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(sync_logger_test PRIVATE
    logger
    third-party
)

# formatter_test.cpp
add_executable(formatter_test
    src/formatter_test.cpp
)

target_include_directories(formatter_test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(formatter_test PRIVATE
    logger
    third-party
)

# rotate_logger_test
add_executable(rotate_logger_test
    src/rotate_logger_test.cpp
)

target_include_directories(rotate_logger_test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(rotate_logger_test PRIVATE
    logger
    third-party
)

# timed_logger_test
add_executable(timed_logger_test
    src/timed_logger_test.cpp
)

target_include_directories(timed_logger_test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(timed_logger_test PRIVATE
    logger
    third-party
)

# async_logger_test
add_executable(async_logger_test
    src/async_logger_test.cpp
)

target_include_directories(async_logger_test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(async_logger_test PRIVATE
    logger
    third-party
)