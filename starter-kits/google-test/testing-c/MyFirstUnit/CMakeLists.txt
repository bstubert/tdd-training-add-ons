# Copyright (C) 2021, Burkhard Stubert (DBA Embedded Use)

cmake_minimum_required(VERSION 3.14)

project(my_first_unit LANGUAGES CXX)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG master
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(${PROJECT_NAME}
    my_first_test_for_first_unit.cpp
    my_second_test_for_first_unit.cpp
    ${GTestFiles})
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

