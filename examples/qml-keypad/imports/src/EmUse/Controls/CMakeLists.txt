# Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

cmake_minimum_required(VERSION 3.15)

project(EmUseControls)

find_package(Qt6 COMPONENTS Core Quick REQUIRED)

qt_add_qml_module(${PROJECT_NAME}
    URI EmUse.Controls
    VERSION 0.1
    RESOURCE_PREFIX /imports
    QML_FILES Keypad.qml
)

add_library(EmUse::Controls ALIAS ${PROJECT_NAME})

target_compile_definitions(${PROJECT_NAME}
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

target_link_libraries(${PROJECT_NAME}
  PRIVATE Qt6::Core Qt6::Quick)


