cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 11)


include(FetchContent)
FetchContent_Declare(
    googletest 
    GIT_REPOSITORY  https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    tests
    tests.cc
)
target_link_libraries(
    tests 
    GTest::gtest_main
    GTest::gmock_main
)
include(GoogleTest)
gtest_discover_tests(tests)