#ifndef TASK_TEMPO_H
#define TASK_TEMPO_H

#include <definicoes.h>
#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

#include <restServer.h>

#define KEY_CLIMATE "main"
#define VALUE_TEMP "temp"
#define VALUE_HUM "humidity"

#define KEY_RAIN  "data"
#define INDEX_RAIN 0
#define VALUE_RAIN "pop"

#define KEY_EURO "EURBRL"
#define VALUE_EURO "ask"
#define KEY_DOLAR "USDBRL"
#define VALUE_DOLAR "ask"

#define KEY_COVID "data"
#define VALUE_CASOS "confirmed"
#define VALUE_DEATHS "deaths"


extern QueueHandle_t xQueue_temp;
extern QueueHandle_t xQueue_hum;
extern QueueHandle_t xQueue_rain;
extern QueueHandle_t xQueue_dolar;
extern QueueHandle_t xQueue_euro;
extern QueueHandle_t xQueue_casos_covid;
extern QueueHandle_t xQueue_mortes_covid;
extern QueueHandle_t xQueue_notice;

void taskTempo(void *pvParameters );
void taskTempoBegin();

void configTemp();
void configHumidity();
void configRain();
void configCoin();
void configCovid();
void configNewsNotices();




#endif