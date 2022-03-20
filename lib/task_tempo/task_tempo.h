#ifndef TASK_TEMPO_H
#define TASK_TEMPO_H

#include <definicoes.h>
#include <Arduino.h>
//#include "FreeRTOS.h"
//#include "queue"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

void taskTempo(void *pvParameters );
void taskTempoBegin();



#endif