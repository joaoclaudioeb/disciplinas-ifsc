#ifndef RPPICOCALLBACK_H
#define RPPICOCALLBACK_H

#include "hardware/adc.h"
#include "hardware/regs/adc.h"
#include "pico/stdlib.h"
#include "./src-gen/Statechart.h"

class RPPicoCallback : public Statechart::OperationCallback {
public:
    // Construtor que recebe ponteiro da máquina
    RPPicoCallback(Statechart* statechart) : sm(statechart) {
        stdio_init_all();
        adc_init();
        adc_set_temp_sensor_enabled(true);
        adc_select_input(4); // canal 4 = sensor interno de temperatura
    }

    void pinMode(sc_integer pin, sc_integer mode) override {
        gpio_init(pin);
        if (mode == 1) {
            gpio_set_dir(pin, GPIO_OUT);
        } else {
            gpio_set_dir(pin, GPIO_IN);
        }
    }

    void digitalWrite(sc_integer pin, sc_integer value) override {
        if (value == 1) {
            gpio_put(pin, true);
        } else {
            gpio_put(pin, false);
        }
    }

    sc_integer readTemp() override {
        const float conversion_factor = 3.3f / (1 << 12);
        uint16_t raw = adc_read();
        float voltage = raw * conversion_factor;
        float temp_c = 27.0 - (voltage - 0.706) / 0.001721;

        return static_cast<sc_integer>(temp_c);
    }

private:
    Statechart* sm;
};

#endif
