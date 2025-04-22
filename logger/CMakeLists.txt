file(GLOB_RECURSE LOGGER_SOURCES "*.cpp")

add_library(logger STATIC ${LOGGER_SOURCES})

target_include_directories(logger PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

find_package(Threads REQUIRED)

target_link_libraries(logger PRIVATE third-party Threads::Threads)
