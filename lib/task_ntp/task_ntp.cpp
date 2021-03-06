#include <task_ntp.h>

TaskHandle_t handle_ntp;

void task_ntp(void *pvParameters)
{

    String data;
    String hora;
    String lastHora;
    initRelogio();

    while (1)
    {

        data = getDate();
        lastHora = getTime();  
        xQueueOverwrite(xQueue_currentDate, (void * )&data);

        if(!lastHora.equals(hora))
        {
            hora = lastHora;    
            Serial.print("\nLAST HORA: ");
            Serial.print(lastHora);
            xQueueSend(xQueue_currentHours, &hora, 100);
        }
        //xQueueOverwrite(xQueue_currentHours, (void *)&hora);
        
        vTaskDelay(pdMS_TO_TICKS(TIME_REFRESH_NTP));

    }
    
}

void taskNtpBegin()
{
     xTaskCreate( task_ntp /* Funcao a qual esta implementado o que a tarefa deve fazer */
                  , "taskTempoDebug" /* Nome (para fins de debug, se necessário) */
                  , TASK_NTP_SIZE /* Tamanho da stack (em words) reservada para essa tarefa */
                  , NULL /* Parametros passados (nesse caso, não há) */
                  , 3 /* Prioridade */
                  , &handle_ntp ); /* Handle da tarefa, opcional */
}