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

// Set REPEAT_CAL to true instead of false to run calibration
// again, otherwise it will only be done once.
// Repeat calibration if you change the screen rotation.
#define REPEAT_CAL false



// Comment out to stop drawing black spots
//#define BLACK_SPOT

// Switch position and size
#define FRAME_X 100
#define FRAME_Y 64
#define FRAME_W 120
#define FRAME_H 50

// Red zone size
#define REDBUTTON_X FRAME_X
#define REDBUTTON_Y FRAME_Y
#define REDBUTTON_W (FRAME_W/2)
#define REDBUTTON_H FRAME_H

// Green zone size
#define GREENBUTTON_X (REDBUTTON_X + REDBUTTON_W)
#define GREENBUTTON_Y FRAME_Y
#define GREENBUTTON_W (FRAME_W/2)
#define GREENBUTTON_H FRAME_H


extern TaskHandle_t handle_btn;

void greenBtn();
void redBtn();
void drawFrame();
void touch_calibrate();


void taskDisplay(void *pvParameters );
void taskDisplayBegin();



#endif