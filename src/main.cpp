#include <main.h>
#include <LittleFS.h> 
#include <TFT_eSPI.h> 



void setup() 
  {
   
    //pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);
    WiFi.begin("NINO", "ra201291");

    Serial.print("CONECTANDO");

    while (WiFi.status() != WL_CONNECTED)
    {
      Serial.print(".");
      vTaskDelay(pdMS_TO_TICKS(500));
    }

    taskTempoBegin();
    taskDisplayBegin();


  } //end setup


void loop() 
  {
     vTaskDelay(pdMS_TO_TICKS(5000));
  } // end loop

 
