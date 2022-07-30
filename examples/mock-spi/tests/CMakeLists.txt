cmake_minimum_required(VERSION 3.19)

project(full_duplex_spi LANGUAGES CXX C)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME}
    tst_full_duplex_spi.cpp
    ../Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_spi.c
    ../doubles/fakes-spi.c
)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_compile_definitions(${PROJECT_NAME} PRIVATE
    STM32F205xx
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ../Inc
    ../doubles
    ../Drivers/STM32F2xx_HAL_Driver/Inc/
    ../Drivers/CMSIS/Device/ST/STM32F2xx/Include/
)

target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
