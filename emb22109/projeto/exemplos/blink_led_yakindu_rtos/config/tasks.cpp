//!
//! @file tasks.cpp
//!
//! @brief This file creates all the project's tasks.
//!
//! @author João Cláudio Elsen Barcellos <joaoclaudiobarcellos@gmail.com>
//! @version 0.0.0
//!
//! @date 06/08/2024
//!

//! Project-specific Drivers
#include "config.h"
#include "tasks.h"

//! Project-specific Headers
#include "../tasks/startup.h"
#include "../tasks/led_control.h"

void create_tasks(void) {

#if EN_TASK_STARTUP == 1
    xTaskCreate(vTaskStartup, TASK_STARTUP_NAME, TASK_STARTUP_STACK_SIZE, nullptr, TASK_STARTUP_PRIORITY, &xTaskStartupHandle);
    
    //! Set the core affinity mask for the task */
    vTaskCoreAffinitySet(xTaskStartupHandle, TASK_STARTUP_CORE);

    if (xTaskStartupHandle == NULL) {
        //! Error creating the startup task
    }
    //! EN_TASK_STARTUP    
#endif

#if EN_TASK_LED_CONTROL == 1
    xTaskCreate(vTaskLedControl, TASK_LED_CONTROL_NAME, TASK_LED_CONTROL_STACK_SIZE, nullptr, TASK_LED_CONTROL_PRIORITY, &xTaskLedControlHandle);
    
    //! Set the core affinity mask for the task */
    vTaskCoreAffinitySet(xTaskLedControlHandle, TASK_LED_CONTROL_CORE);

    if (xTaskLedControlHandle == NULL) {
        //! Error creating the startup task
    }
    //! EN_TASK_LED_CONTROL    
#endif

    create_event_groups(); 
}

void create_event_groups(void)
{
    task_startup_status = xEventGroupCreate();

    if (task_startup_status == NULL)
    {
        //! Error creating the startup status event group
    }
}
