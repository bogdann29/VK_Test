cmake_minimum_required(VERSION 3.22)
project(Graph)

set(CMAKE_CXX_STANDARD 20)

include_directories(source)
add_subdirectory(src)
enable_testing()
add_subdirectory(tests)

set(SOURCE_FILES main.cpp)
add_executable(main ${SOURCE_FILES})

target_link_libraries(main Graph_lib)