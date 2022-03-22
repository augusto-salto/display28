#ifndef MAIN_H
#define MAIN_H
#define _DISABLE_TLS_

    #include <Arduino.h>
    #include <WiFi.h>
  
    #include "freertos/FreeRTOS.h"
    #include "freertos/queue.h"
    #include "task_display.h"
    #include "task_tempo.h"
    #include <task_ntp.h>
    #include "task_firebase.h"

QueueHandle_t xQueue_temp;
QueueHandle_t xQueue_hum;
QueueHandle_t xQueue_rain;

QueueHandle_t xQueue_dolar;
QueueHandle_t xQueue_euro;
QueueHandle_t xQueue_casos_covid;
QueueHandle_t xQueue_mortes_covid;
QueueHandle_t xQueue_notice;
QueueHandle_t xQueue_time;
QueueHandle_t xQueue_btn;
QueueHandle_t xQueue_currentHours;
QueueHandle_t xQueue_currentDate;

QueueHandle_t xQueue_nivel;
QueueHandle_t xQueue_total;
QueueHandle_t xQueue_vazao;

SemaphoreHandle_t xSerial_http_request;
SemaphoreHandle_t xTft_semaphore;

void initializeQueue();
void initializeSemaphore();


#endif