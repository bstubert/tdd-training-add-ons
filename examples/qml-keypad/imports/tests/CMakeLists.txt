# Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

cmake_minimum_required(VERSION 3.15)

project(test_qml_keypad LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Quick QuickTest REQUIRED)

add_executable(${PROJECT_NAME}
    tst_keypad.cpp
)

set_source_files_properties(
    ../src/EmUse/Controls/Keypad.qml PROPERTIES
        QT_RESOURCE_ALIAS Keypad.qml)

qt_add_qml_module(${PROJECT_NAME}
    URI KeypadTest
    VERSION 0.1
    RESOURCE_PREFIX /
    QML_FILES tst_enter_number.qml ../src/EmUse/Controls/Keypad.qml
)


target_link_libraries(${PROJECT_NAME}
  PRIVATE Qt6::Quick Qt6::QuickTest)

include(CTest)
add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)
