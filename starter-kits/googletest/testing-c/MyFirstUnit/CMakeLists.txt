# Copyright (C) 2021, Burkhard Stubert (DBA Embedded Use)

cmake_minimum_required(VERSION 3.14)

project(my_first_unit LANGUAGES CXX C)

enable_testing()
add_executable(${PROJECT_NAME}
    my_first_test_for_first_unit.cpp
#    my_second_test_for_first_unit.cpp
    ${GTestFiles})
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

