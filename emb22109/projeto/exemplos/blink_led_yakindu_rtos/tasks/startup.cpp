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

//! External Libraries
#include "projdefs.h"         //!< FreeRTOS

//! Project-specific Drivers
#include "../src-gen/Statechart.h"
#include "../RPPicoCallback.h"

//! Project-specific Headers
#include "startup.h"

extern Statechart statechart;
extern RPPicoCallback callback;

TaskHandle_t xTaskStartupHandle;

EventGroupHandle_t task_startup_status;

void vTaskStartup(void *pvParameters)
{

    TickType_t last_cycle = xTaskGetTickCount();
    
    statechart.setOperationCallback(&callback);
    statechart.enter();

    vTaskDelayUntil(&last_cycle, pdMS_TO_TICKS(1000 / portTICK_PERIOD_MS));
    
    statechart.raiseInitEvent();
    
    xEventGroupSetBits(task_startup_status, TASK_STARTUP_DONE);

    vTaskSuspend(xTaskStartupHandle);
};
