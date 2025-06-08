cmake_minimum_required(VERSION 3.12)

set(PICO_SDK_PATH ${CMAKE_SOURCE_DIR}/../sdk/pico)
set(FREERTOS_KERNEL_PATH ${CMAKE_SOURCE_DIR}/../os/FreeRTOS)

include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)
include(${FREERTOS_KERNEL_PATH}/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)

project(main_project)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS On)

pico_sdk_init()

add_library(freertos STATIC
  ${FREERTOS_KERNEL_PATH}
  ${FREERTOS_KERNEL_PATH}/portable/ThirdParty/GCC/RP2040/port.c
)

target_include_directories(freertos PUBLIC
  .
  ${FREERTOS_KERNEL_PATH}/include
  ${FREERTOS_KERNEL_PATH}/portable/ThirdParty/GCC/RP2040/include
)

target_link_libraries(freertos
  FreeRTOS-Kernel
  FreeRTOS-Kernel-Heap3
  pico_stdlib
)

add_executable(main
  main.cpp
  RPPicoCallback.cpp
  ${CMAKE_SOURCE_DIR}/src-gen/Statechart.cpp
  ${CMAKE_SOURCE_DIR}/tasks/led_control.cpp
  ${CMAKE_SOURCE_DIR}/tasks/startup.cpp
  ${CMAKE_SOURCE_DIR}/config/tasks.cpp
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
  hardware_adc
  freertos
)
