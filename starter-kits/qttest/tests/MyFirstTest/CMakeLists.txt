project(MyFirstTest)

cmake_minimum_required(VERSION 3.10)

find_package(Qt6 COMPONENTS Test Core)
if (NOT Qt6_FOUND)
    find_package(Qt5 5.15 COMPONENTS Test Core REQUIRED)
endif()

enable_testing()

add_executable(${PROJECT_NAME}
    MyFirstTest.cpp
)

add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)

# MY_INCLUDE_ROOT is relative path from this directory to the root of your source tree.
# The target include directories are relative to ${MY_INCLUDE_ROOT}.
#set(MY_INCLUDE_ROOT ../../..)
#target_include_directories(${PROJECT_NAME}
#    PRIVATE
#        ${MY_INCLUDE_ROOT}/to/include
#)

target_link_libraries(
    ${PROJECT_NAME}
    Qt::Test Qt::Core
)

