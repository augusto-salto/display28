#ifndef TASK_NTP_H
#define TASK_NTP_H


    #include <freertos/FreeRTOS.h>
    #include <freertos/queue.h>
    #include <definicoes.h>
    #include <ntp_lib.h>


    extern QueueHandle_t xQueue_currentHours;
    extern QueueHandle_t xQueue_currentDate;
    
    void task_ntp(void *pvParameters);
    void taskNtpBegin();

#endif