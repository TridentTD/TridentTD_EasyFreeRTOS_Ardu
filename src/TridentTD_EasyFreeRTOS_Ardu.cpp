#include "TridentTD_EasyFreeRTOS_Ardu.h"

#ifndef TASK_RESUME
#define TASK_RESUME(c)  vTaskResume(c)
#endif
#ifndef TASK_STOP
#define TASK_STOP(c)    vTaskSuspend(c)
#endif

void EasyFreeRTOS_Ardu::stop()   { TASK_STOP(_task_handler);   }
void EasyFreeRTOS_Ardu::resume() { TASK_RESUME(_task_handler); }

void EasyFreeRTOS_Ardu::start( TaskFunction_t fn, void * const arg, const uint32_t StackDepth) {
  String task_name = String("FreeRTOS_Task_")+ String(random(10000));
  xTaskCreate( fn, task_name.c_str(),StackDepth, arg, 5, &ptr->_task_handler); 
}

//portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED;
