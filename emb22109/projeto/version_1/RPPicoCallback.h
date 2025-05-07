#ifndef RPPICOCALLBACK_H
#define RPPICOCALLBACK_H

#include "pico/stdlib.h"
#include "Statechart.h"

class RPPicoCallback : public Statechart::OperationCallback {
public:
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
};


#endif
