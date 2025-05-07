#include "Statechart.h"
#include "RPPicoCallback.h"
#include "RPPicoTimer.h"
#include "pico/stdlib.h"

int main() {
    stdio_init_all();

    Statechart statechart;
    RPPicoCallback callback;
    RPPicoTimer timer;

    statechart.setOperationCallback(&callback);
    statechart.setTimerService(&timer);

    statechart.enter();
    statechart.raiseToggle();
    
    while (true) {
        timer.processTimers();   // processa eventos do timer
        statechart.runCycle();   // executa a máquina de estados

        sleep_ms(1); // espera mínima para não consumir toda CPU
    }

    return 0;
}
