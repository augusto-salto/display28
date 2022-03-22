#ifndef TASK_BTN_DISPLAY_H
#define TASK_BTN_DISPLAY_H


    #include <definicoes.h>
    #include <Arduino.h>
    #include "freertos/FreeRTOS.h"
    #include "freertos/queue.h"
    #include <TFT_eSPI.h> 

    extern TFT_eSPI tft;
    extern QueueHandle_t xQueue_btn;
    extern SemaphoreHandle_t xTft_semaphore;

    void taskBtn(void *pvParameters );
    void taskBtnBegin();



#endif