# Copyright (C) 2021, Burkhard Stubert (DBA Embedded Use)

cmake_minimum_required(VERSION 3.14)

project(my_first_test LANGUAGES CXX C)

enable_testing()

add_executable(${PROJECT_NAME}
    my_first_test.cpp
    ${GTestFiles}
)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

# MY_INCLUDE_ROOT is relative path from this directory to the root of your source tree.
# The target include directories are relative to ${MY_INCLUDE_ROOT}.
#set(MY_INCLUDE_ROOT ../../..)
#target_include_directories(${PROJECT_NAME}
#    PRIVATE
#        ${MY_INCLUDE_ROOT}/to/include
#)

target_link_libraries(${PROJECT_NAME} PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

