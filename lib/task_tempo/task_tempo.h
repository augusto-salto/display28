#ifndef TASK_TEMPO_H
#define TASK_TEMPO_H

#include <definicoes.h>
#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

#include <restServer.h>

extern QueueHandle_t xQueue_temp;
extern QueueHandle_t xQueue_hum;
extern QueueHandle_t xQueue_rain;
extern QueueHandle_t xQueue_dolar;
extern QueueHandle_t xQueue_euro;

void taskTempo(void *pvParameters );
void taskTempoBegin();

void configTemp();
void configHumidity();
void configRain();
void configEuro();
void configDolar();



#endif