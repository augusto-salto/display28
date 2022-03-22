#ifndef TASK_DISPLAY_H
#define TASK_DISPLAY_H

#include <definicoes.h>
#include <Arduino.h>
//#include "FreeRTOS.h"
//#include "queue"
//#include "TFT_eSPI.h"  
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include <SPI.h>
#include <FS.h>
#include <LittleFS.h> 
#include <task_btn_display.h>
#include <calibrate.h>


#define CALIBRATION_FILE "/TouchCalData3"

#define MAXDELAY 50

// Set REPEAT_CAL to true instead of false to run calibration
// again, otherwise it will only be done once.
// Repeat calibration if you change the screen rotation.
#define REPEAT_CAL false





extern TaskHandle_t handle_btn;

extern QueueHandle_t xQueue_temp;
extern QueueHandle_t xQueue_hum;
extern QueueHandle_t xQueue_rain;
extern QueueHandle_t xQueue_nivel;
extern QueueHandle_t xQueue_dolar;
extern QueueHandle_t xQueue_euro;
extern QueueHandle_t xQueue_casos_covid;
extern QueueHandle_t xQueue_mortes_covid;
extern QueueHandle_t xQueue_notice;
extern QueueHandle_t xQueue_time;
extern QueueHandle_t xQueue_btn;
extern QueueHandle_t xQueue_currentHours;
extern QueueHandle_t xQueue_currentDate;
extern QueueHandle_t xQueue_nivel;
extern QueueHandle_t xQueue_total;
extern QueueHandle_t xQueue_vazao;

extern SemaphoreHandle_t xTft_semaphore;


void taskDisplay(void *pvParameters );
void taskDisplayBegin();
void refreshValues();



#endif