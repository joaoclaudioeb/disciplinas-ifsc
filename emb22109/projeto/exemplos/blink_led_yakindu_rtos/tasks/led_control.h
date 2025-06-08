//!
//! @file led_control.h
//!
//! @brief This file contains the LED control routine task header.
//!
//! @author João Cláudio Elsen Barcellos  <joaoclaudiobarcellos@gmail.com>
//! @version 0.0.0
//!
//! @date 06/08/2024
//!

#ifndef LED_CONTROL_H_
#define LED_CONTROL_H_

//! External Libraries
#include <FreeRTOS.h>
#include <task.h>

//! Task properties
#define TASK_LED_CONTROL_NAME                 "LED control"
#define TASK_LED_CONTROL_STACK_SIZE           1000
#define TASK_LED_CONTROL_PRIORITY             5
#define TASK_LED_CONTROL_PERIOD_MS            500 / portTICK_PERIOD_MS
#define TASK_LED_CONTROL_CORE                 (( 1 << 1 ) | ( 1 << 0 )) //!< Can run in both cores

//!
//! @brief Heartbeat task handle.
//!
extern TaskHandle_t xTaskLedControlHandle;

//!
//! \brief Basic LED control task
//! 
//! \param pvParameters Not used
//!
void vTaskLedControl(void *pvParameters);

//! LED_CONTROL_HPP_
#endif 
