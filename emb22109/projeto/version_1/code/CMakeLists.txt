cmake_minimum_required(VERSION 3.12)

set(PICO_SDK_PATH ${CMAKE_SOURCE_DIR}/sdk/pico)
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(main_project C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

pico_sdk_init()

add_executable(main
    main.cpp
    Statechart.cpp
)

target_include_directories(main PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Adicione as bibliotecas essenciais para GPIO e Timer
target_link_libraries(main 
    pico_stdlib 
    hardware_gpio
    hardware_timer
    hardware_pwm
    hardware_adc
)

pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)

pico_add_extra_outputs(main)



# cmake_minimum_required(VERSION 3.12)

# # Configuração básica do SDK do Pico
# set(PICO_SDK_PATH ${CMAKE_SOURCE_DIR}/sdk/pico)  # Mantenha seu caminho local
# include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# project(blinky_statechart)  # Nome do projeto alterado
# set(CMAKE_C_STANDARD 11)
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_EXPORT_COMPILE_COMMANDS On)

# pico_sdk_init()

# # --- Arquivos do Statechart (gerados pelo itemis CREATE) ---
# add_executable(blinky_statechart
#   main.cpp                  # Seu arquivo principal (com o código de integração)
#   Statechart.cpp            # Código gerado pelo itemis CREATE
# )

# # --- Bibliotecas do Pico ---
# target_link_libraries(blinky_statechart
#   pico_stdlib
#   hardware_gpio             # Para GPIO (opcional, mas recomendado)
# )

# # --- Configurações adicionais ---
# pico_enable_stdio_usb(blinky_statechart 1)  # Habilita output USB (para debug)
# pico_add_extra_outputs(blinky_statechart)   # Gera .uf2 e .hex
