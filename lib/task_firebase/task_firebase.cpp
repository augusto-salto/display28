#include "task_firebase.h"

    #include "FreeRTOS.h"
    #include "freertos/queue.h"

TaskHandle_t handle_firebase;

void task_firebase(void *pVparameters)
{
    FireBaseClass firebaseClient = FireBaseClass();
    int nivel;
    int total;
    float vazao;

    while (1)
    {
        nivel = firebaseClient.getNivel();
        total = firebaseClient.getTotal();
        vazao = firebaseClient.getVazao();

       
        xQueueOverwrite(xQueue_nivel, (void *)&nivel);
        xQueueOverwrite(xQueue_total, (void *)&total);
        xQueueOverwrite(xQueue_vazao, (void *)&vazao);

        vTaskDelay(pdMS_TO_TICKS(TIME_REFRESH_FIREBASE));
    }
    
}

void taskFirebaseBegin()
{

     xTaskCreate( task_firebase /* Funcao a qual esta implementado o que a tarefa deve fazer */
                  , "taskFirebaseDebug" /* Nome (para fins de debug, se necessário) */
                  , TASK_FIREBASE_SIZE /* Tamanho da stack (em words) reservada para essa tarefa */
                  , NULL /* Parametros passados (nesse caso, não há) */
                  , 10 /* Prioridade */
                  , &handle_firebase ); /* Handle da tarefa, opcional */

}