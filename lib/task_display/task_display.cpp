#include <task_display.h>
#include <TFT_eSPI.h> 

TaskHandle_t handle_display;
TFT_eSPI tft = TFT_eSPI();

int dtemperature = 0;
int dhumidity = 0;
int drainPossibility = 0;
float dfloatDolar = 0;
float dfloatEuro = 0;
int dcasosCovid = 0;
int dmortesCovid = 0;
String dnotice = "Carregando...";

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
 

  //taskBtnBegin();

    while (1)
    {

      refreshValues();

      tft.setTextSize(2);
      tft.fillScreen(TFT_WHITE);
      tft.setCursor(10, 10);
      tft.print("TEMPERATURA: ");
      tft.print(String(dtemperature));

      tft.setCursor(10, 30);
      tft.print("HUMIDADE: ");
      tft.print(String(dhumidity));
      tft.print("%");

      tft.setCursor(10, 50);
      tft.print("EURO: R$");
      tft.print(dfloatEuro);

      tft.setCursor(10, 70);
      tft.print("DOLAR: R$");
      tft.print(dfloatDolar);

      
      tft.setCursor(10, 90);
      tft.print("CASOS COVID: ");
      tft.setTextSize(1.8);
      tft.print(dcasosCovid);

      tft.setCursor(10, 120);
      tft.setTextSize(2);
      tft.print("MORTES COVID: ");
      tft.setTextSize(1.8);
      tft.print(dmortesCovid);
    
      
      vTaskDelay(pdMS_TO_TICKS(1000));

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



void  refreshValues()
{
      xQueueReceive(xQueue_temp, (void *)&dtemperature, MAXDELAY);
      

      xQueueReceive(xQueue_hum, (void *)&dhumidity, MAXDELAY);
      

      xQueueReceive(xQueue_rain, (void *)&drainPossibility, MAXDELAY);
      

      xQueueReceive(xQueue_euro, (void *)&dfloatEuro, MAXDELAY);
     
      xQueueReceive(xQueue_dolar, (void *)&dfloatDolar, MAXDELAY);
      
      
      xQueueReceive(xQueue_casos_covid, (void *)&dcasosCovid, MAXDELAY);
      

      xQueueReceive(xQueue_mortes_covid, (void *)&dmortesCovid, MAXDELAY);
      

      xQueueReceive(xQueue_notice, (void *)&dnotice, MAXDELAY);  
      


      #if DEBUG_QUEUE_VALUES_AT_DISPLAY == 1
      Serial.print("\nTEMPERATURA: ");
      Serial.print(dtemperature);
      Serial.print("\nHUMIDADE: ");
      Serial.print(dhumidity);
      Serial.print("\nRAIN: ");
      Serial.print(drainPossibility);
      Serial.print("\nDOLAR: ");
      Serial.print(dfloatDolar);
      Serial.print("\nEURO: ");
      Serial.print(dfloatEuro);
      Serial.print("\nCASOS COVID: ");
      Serial.print(dcasosCovid);
      Serial.print("\nMORTES COVID: ");
      Serial.print(dmortesCovid);
      Serial.print("\nNOTICIA: ");
      Serial.print(dnotice);

      #endif
}

