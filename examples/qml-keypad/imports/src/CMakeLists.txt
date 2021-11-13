# Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

cmake_minimum_required(VERSION 3.15)

project(EmUseControls LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Core Quick REQUIRED)

#add_executable(${PROJECT_NAME}
#    main.cpp
#    qml.qrc
#)

qt_add_qml_module(${PROJECT_NAME}
    URI EmUse.Controls
    VERSION 0.1
    QML_FILES EmUse/Controls/Keypad.qml
)


target_compile_definitions(${PROJECT_NAME}
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

target_link_libraries(${PROJECT_NAME}
  PRIVATE Qt6::Core Qt6::Quick)


