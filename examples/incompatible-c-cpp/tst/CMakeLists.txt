# Copyright (C) 2021, Burkhard Stubert (DBA Embedded Use)

cmake_minimum_required(VERSION 3.14)

project(test_incompatible-c-cpp LANGUAGES CXX C)

enable_testing()
add_executable(${PROJECT_NAME}
    ../src/ringbuffer.c
    test_incompatible-c-cpp.cpp
    ${GTestFiles})
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PRIVATE ../src)
target_link_libraries(${PROJECT_NAME} PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

