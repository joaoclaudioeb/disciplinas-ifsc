/**
 * @file RPPicoCallback.h
 * @brief Interface de callback para integração do Statechart com hardware RP2040
 */

#ifndef RPPICOCALLBACK_H
#define RPPICOCALLBACK_H

#include "hardware/adc.h"
#include "hardware/regs/adc.h"
#include "pico/stdlib.h"
#include "./src-gen/Statechart.h"

// Forward declaration da classe Statechart
class Statechart;

/**
 * @class RPPicoCallback
 * @brief Implementação das operações de hardware para o Statechart
 */
class RPPicoCallback : public Statechart::OperationCallback {
public:
    explicit RPPicoCallback(Statechart* statechart);
    
    void pinMode(sc_integer pin, sc_integer mode) override;
    void digitalWrite(sc_integer pin, sc_integer value) override;
    sc_integer readTemp() override;

private:
    Statechart* sm;
};

// Declaração externa após a definição da classe
extern RPPicoCallback callback;

#endif // RPPICOCALLBACK_H
