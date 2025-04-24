add_subdirectory(googletest)

add_library(third-party INTERFACE)

target_include_directories(third-party INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(third-party INTERFACE
    GTest::gtest
    GTest::gtest_main
)