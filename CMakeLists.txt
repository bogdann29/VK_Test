cmake_minimum_required(VERSION 3.22)
project(Graph)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED COMPONENTS program_options)

include_directories(${Boost_INCLUDE_DIRS} source)

include_directories(source)
add_subdirectory(src)
enable_testing()
add_subdirectory(tests)

set(SOURCE_FILES main.cpp)
add_executable(main ${SOURCE_FILES})

target_link_libraries(main Graph_lib Boost::program_options)