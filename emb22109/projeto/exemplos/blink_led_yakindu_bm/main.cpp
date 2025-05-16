#include "./src-gen/Statechart.h"
#include "RPPicoCallback.h"
#include "RPPicoTimer.h"
#include "pico/stdlib.h"

int main() {
    Statechart statechart;
    RPPicoCallback callback(&statechart); // ← CORRIGIDO AQUI
    RPPicoTimer timer;

    statechart.setOperationCallback(&callback);
    statechart.setTimerService(&timer);

    statechart.enter();
    statechart.raiseToggle();
    
    while (true) {
        timer.processTimers();   // processa eventos do timer
        statechart.runCycle();   // executa a máquina de estados
        sleep_ms(1);
    }

    return 0;
}
