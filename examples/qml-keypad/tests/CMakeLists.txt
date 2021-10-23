# Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

cmake_minimum_required(VERSION 3.15)

project(test_qml_keypad LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS QuickTest Qml REQUIRED)

include(CTest)

add_executable(${PROJECT_NAME}
    tst_keypad.cpp
    tst_keypad.qrc
)

add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE Qt5::QuickTest Qt5::Qml)
