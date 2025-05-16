cmake_minimum_required(VERSION 3.12)

set(PICO_SDK_PATH ${CMAKE_SOURCE_DIR}/../sdk/pico)

include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(main_project)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS On)

pico_sdk_init()

target_link_libraries(pico_stdlib)

add_executable(main
  main.cpp
  ${CMAKE_SOURCE_DIR}/src-gen/Statechart.cpp
)

target_include_directories(main PRIVATE
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/srg-gen/
)

pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)

pico_add_extra_outputs(main)

target_link_libraries(main 
    pico_stdlib 
    hardware_gpio
    hardware_timer
    hardware_pwm
    hardware_adc)
