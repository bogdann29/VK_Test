project(Google_tests)

file(GLOB tests_SRC
        "*.cpp"
        )
        
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(run_tests ${tests_SRC})

target_link_libraries(run_tests Graph_lib gtest gtest_main)

add_test(NAME DijkstraTest COMMAND run_tests)
add_test(NAME ReadFileTest COMMAND run_tests)