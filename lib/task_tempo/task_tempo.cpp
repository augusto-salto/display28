#include <task_tempo.h>


TaskHandle_t handle_tempo;


void taskTempo(void *pvParameters )
{
    while (1)
    {
        //digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
        vTaskDelay(pdMS_TO_TICKS(500));
    }
    
}

void taskTempoBegin()
{
     xTaskCreate( taskTempo /* Funcao a qual esta implementado o que a tarefa deve fazer */
                  , "taskSensorDebug" /* Nome (para fins de debug, se necessário) */
                  , TASK_TEMPO_SIZE /* Tamanho da stack (em words) reservada para essa tarefa */
                  , NULL /* Parametros passados (nesse caso, não há) */
                  , 3 /* Prioridade */
                  , &handle_tempo ); /* Handle da tarefa, opcional */
}

