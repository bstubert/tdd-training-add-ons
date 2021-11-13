# Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

cmake_minimum_required(VERSION 3.15)

project(TestKeypad)

find_package(Qt6 COMPONENTS Quick QuickTest REQUIRED)

add_executable(${PROJECT_NAME}
    tst_keypad.cpp
)

set_source_files_properties(
    ../src/EmUse/Controls/Keypad.qml PROPERTIES
        QT_RESOURCE_ALIAS Keypad.qml)

qt_add_qml_module(${PROJECT_NAME}
    URI EmUse.Tests.Keypad
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
