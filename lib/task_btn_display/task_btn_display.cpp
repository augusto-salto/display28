#include <task_btn_display.h>

TaskHandle_t handle_btn;


void taskBtn(void *pvParameters)
{

    while (1)
    {
          uint16_t x, y;

  // See if there's any touch data for us
  if (tft.getTouch(&x, &y))
  {
    Serial.print("\n(TASK BTN)COORDENADA X: ");
    Serial.print(x);
    Serial.print("\n(TASK BTN)COORDENADA Y: ");
    Serial.print(y);
    Serial.print("\n");
  }
        vTaskDelay(pdMS_TO_TICKS(100));
    }
    
}


void taskBtnBegin()
{
     xTaskCreate( taskBtn /* Funcao a qual esta implementado o que a tarefa deve fazer */
                  , "taskBtnDebug" /* Nome (para fins de debug, se necessário) */
                  , TASK_TOUCH_BTN_SIZE /* Tamanho da stack (em words) reservada para essa tarefa */
                  , NULL /* Parametros passados (nesse caso, não há) */
                  , 10 /* Prioridade */
                  , &handle_btn ); /* Handle da tarefa, opcional */
}