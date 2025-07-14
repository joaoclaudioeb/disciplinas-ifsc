//!
//! @file heartbeat.cpp
//!
//! @brief This file contains the heartbeat task implementation.
//!
//! @author Ramon de Araujo Borba <ramonborba97@gmail.com>
//! @version 0.0.0
//!
//! @date 06/08/2024
//!


//! C++ standard library
#include <cstdint>           

#include <stdio.h>
#include "pico/stdlib.h"

//! External Libraries
#include "projdefs.h"         //!< FreeRTOS

//! Project-specific Drivers
#include "../src-gen/Statechart.h"
#include "../RPPicoCallback.h"

//! Project-specific Headers
#include "led_control.h"

extern Statechart statechart;
extern RPPicoCallback callback;

TaskHandle_t xTaskLedControlHandle;

void vTaskLedControl(void *pvParameters) {

    const float conversion_factor = 3.3f / (1 << 12);
    uint16_t raw;
    float voltage;
    float temp_c;
    
    while (true) {
        TickType_t last_cycle = xTaskGetTickCount();

        statechart.raiseGetTemp;
        
        if (callback.getTemp() < 30)
            statechart.raiseMinTempEvent();
        if (temp_c > 35)
            statechart.raiseMaxTempEvent();

        vTaskDelayUntil(&last_cycle, pdMS_TO_TICKS(TASK_LED_CONTROL_PERIOD_MS));
    }

};
