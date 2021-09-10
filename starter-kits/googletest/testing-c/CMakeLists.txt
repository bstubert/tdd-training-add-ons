# Copyright (C) 2021, Burkhard Stubert (DBA Embedded Use)
cmake_minimum_required(VERSION 3.14)

project(UnitTests)

include(CTest)

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

add_subdirectory(MyFirstUnit)
#add_subdirectory(MySecondUnit)
add_subdirectory(ringbuffer)
