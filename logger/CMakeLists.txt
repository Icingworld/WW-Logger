file(GLOB_RECURSE LOGGER_SOURCES "*.cpp")

add_library(logger STATIC ${LOGGER_SOURCES})

target_include_directories(logger PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/Logger"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/Formatter"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/Sinks"
)

find_package(Threads REQUIRED)

target_link_libraries(logger PRIVATE Threads::Threads)
