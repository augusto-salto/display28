#include <task_display.h>
#include <TFT_eSPI.h> 

TaskHandle_t handle_display;
TFT_eSPI tft = TFT_eSPI();


void taskDisplay(void *pvParameters )
{

  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);
  tft.init();
  tft.setRotation(0);
  

  #if FORMAT_CALIBRATION == 1
    deleteCalibration();
  #else
    calibrateTouch(tft);
  #endif


  tft.fillScreen(TFT_WHITE);
  tft.setCursor(70, 130);
  //tft.setTextDatum(5);
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.print("PPP TECH");
 

  taskBtnBegin();

    while (1)
    {
         
      vTaskDelay(pdMS_TO_TICKS(10));
    }
    
}






void taskDisplayBegin()
{
     xTaskCreate( taskDisplay /* Funcao a qual esta implementado o que a tarefa deve fazer */
                  , "taskDisplayDebug" /* Nome (para fins de debug, se necessário) */
                  , TASK_DISPLAY_SIZE /* Tamanho da stack (em words) reservada para essa tarefa */
                  , NULL /* Parametros passados (nesse caso, não há) */
                  , 10 /* Prioridade */
                  , &handle_display ); /* Handle da tarefa, opcional */
}





