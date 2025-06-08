//!
//! @file heartbeat.hpp
//!
//! @brief This file contains the basic test routine task header.
//!
//! @author João Cláudio Elsen Barcellos  <joaoclaudiobarcellos@gmail.com>
//! @version 0.0.0
//!
//! @date 06/08/2024
//!

#ifndef STARTUP_H_
#define STARTUP_H_

//! External Libraries
#include <FreeRTOS.h>    //!< FreeRTOS
#include <task.h>        //!< FreeRTOS
#include <event_groups.h>

//! Task properties
#define TASK_STARTUP_NAME                 "Startup"
#define TASK_STARTUP_STACK_SIZE           100
#define TASK_STARTUP_PRIORITY             5
#define TASK_STARTUP_CORE                 (( 1 << 1 ) | ( 1 << 0 )) //!< Can run in both cores
#define TASK_STARTUP_DONE                 (1U << 0)

//!
//! @brief Heartbeat task handle.
//!
extern TaskHandle_t xTaskStartupHandle;

extern EventGroupHandle_t task_startup_status;
//!
//! \brief Basic heartbeat task
//! 
//! \param pvParameters Not used
//!
void vTaskStartup(void *pvParameters);

//! STARTUP_HPP_
#endif 
