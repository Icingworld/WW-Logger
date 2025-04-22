file(GLOB_RECURSE TEST_SOURCES "*.cpp")

add_executable(logger_test ${TEST_SOURCES})

target_include_directories(logger_test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(logger_test PRIVATE logger)
