cmake_minimum_required(VERSION 3.10)

project(TestContainer)

include(CTest)

set(CMAKE_VERBOSE_MAKEFILE true)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(BUILD_TESTING)
    add_subdirectory(MyFirstTest)
# Add more test cases here!
endif()
