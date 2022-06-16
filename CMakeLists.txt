cmake_minimum_required(VERSION 3.21)
project(HW2_2)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.10.0
)
FetchContent_MakeAvailable(googletest)

set(CMAKE_CXX_STANDARD 20)
set(TEST_NAME HW2_2_tests)
add_subdirectory(BinaryTreeHeader)
add_executable(HW2_2 tests.cpp)
target_link_libraries(HW2_2 gtest_main BinaryTreeHeader)

enable_testing()
include(GoogleTest)
gtest_discover_tests(HW2_2)