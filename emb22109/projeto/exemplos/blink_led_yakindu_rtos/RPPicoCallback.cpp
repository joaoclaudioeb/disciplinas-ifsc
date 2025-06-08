/**
 * @file RPPicoCallback.cpp
 * @brief Implementação do callback para hardware RP2040
 */

#include "RPPicoCallback.h"
#include "./src-gen/Statechart.h"

// Definição da máquina de estados
Statechart statechart;

// Definição do callback
RPPicoCallback callback(&statechart);

// Implementação dos métodos
RPPicoCallback::RPPicoCallback(Statechart* statechart) : sm(statechart) {
    stdio_init_all();
    adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4);
}

void RPPicoCallback::pinMode(sc_integer pin, sc_integer mode) {
    gpio_init(pin);
    if (mode == 1) {
        gpio_set_dir(pin, GPIO_OUT);
    } else {
        gpio_set_dir(pin, GPIO_IN);
    }
}

void RPPicoCallback::digitalWrite(sc_integer pin, sc_integer value) {
    if (value == 1) {
        gpio_put(pin, true);
    } else {
        gpio_put(pin, false);
    }
}

sc_integer RPPicoCallback::readTemp() {
    const float conversion_factor = 3.3f / (1 << 12);
    uint16_t raw = adc_read();
    float voltage = raw * conversion_factor;
    float temp_c = 27.0 - (voltage - 0.706) / 0.001721;

    return static_cast<sc_integer>(temp_c);
}
