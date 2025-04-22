file(GLOB_RECURSE TEST_SOURCES "*.cpp")

add_executable(test ${TEST_SOURCES})

target_link_libraries(test PRIVATE logger)
