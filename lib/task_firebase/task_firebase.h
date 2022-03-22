#ifndef TASK_FIREBASE_H
#define TASK_FIREBASE_H


    #include <SD.h>
    #include <Update.h>

    #include "freertos/FreeRTOS.h"
    #include "freertos/queue.h"
    #include "definicoes.h"
    #include <firebasePPPTech.h>

    extern QueueHandle_t xQueue_nivel;
    extern QueueHandle_t xQueue_total;
    extern QueueHandle_t xQueue_vazao;

    void task_firebase(void *pVparameters);
    void taskFirebaseBegin();










#endif