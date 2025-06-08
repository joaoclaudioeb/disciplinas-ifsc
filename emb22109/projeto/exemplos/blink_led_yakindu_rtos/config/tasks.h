//!
//! @file tasks.h
//!
//! @brief This file creates all the project's tasks.
//!
//! @author João Cláudio Elsen Barcellos <joaoclaudiobarcellos@gmail.com>
//! @version 0.0.0
//!
//! @date 06/08/2024
//!

#ifndef TASKS_H_
#define TASKS_H_

//! External Libraries
#include <FreeRTOS.h>        //!< FreeRTOS
#include <task.h>            //!< FreeRTOS
#include <event_groups.h>    //!< FreeRTOS

//!
//! @brief Startup status event group.
//! 
extern EventGroupHandle_t task_startup_status;

//!
//! @brief Creates the system tasks.
//!
//! @return None.
//!
void create_tasks(void);

//!
//! \brief Creates the system event groups.
//!
//! \return None.
//!
void create_event_groups(void);

//! TASKS_H_
#endif  
