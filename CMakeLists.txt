cmake_minimum_required(VERSION 3.13)

project(pico-FreeRTOS C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(FREERTOS_SOURCE_PATH ${PROJECT_SOURCE_DIR}/freertos)
set(FREERTOS_KERNEL_PATH ${PROJECT_SOURCE_DIR}/freertos/Kernel/)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

pico_sdk_init()

add_compile_options(
        -Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function # we have some for the docs that aren't called
        -Wno-maybe-uninitialized
)

add_subdirectory(./freertos)

if(NOT DEFINED IS_ROOT_PROJECT)
        add_subdirectory(./example)
        set(IS_ROOT_PROJECT true)
endif()