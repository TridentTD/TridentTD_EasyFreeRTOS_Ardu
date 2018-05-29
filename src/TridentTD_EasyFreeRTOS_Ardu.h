#ifndef __TRIDENTTD_EASY_FREERTOS_ARDU_H__
#define __TRIDENTTD_EASY_FREERTOS_ARDU_H__

#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>

#ifndef DELAY
#define DELAY(a) vTaskDelay((a)/portTICK_PERIOD_MS);
#endif

#ifndef VOID
#define VOID
#endif

#ifndef SETUP
#define SETUP()
#endif

#ifndef LOOP
#define LOOP()     for(;;)
#endif


class EasyFreeRTOS_Ardu {
public:
  EasyFreeRTOS_Ardu() {};
  void start( TaskFunction_t fn, void * const arg=NULL, const uint32_t StackDepth=255);
  void stop();
  void resume();
    
  EasyFreeRTOS_Ardu* ptr = const_cast<EasyFreeRTOS_Ardu*>(this);
private:
  TaskHandle_t  _task_handler;
};

#endif //__TRIDENTTD_EASY_FREERTOS_ARDU_H__