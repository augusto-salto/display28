#include <task_display.h>
#include <TFT_eSPI.h> 

 

TaskHandle_t handle_display;
TFT_eSPI tft = TFT_eSPI();
bool SwitchOn = false;


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


  // clear screen
  tft.fillScreen(TFT_WHITE);
  tft.setCursor(70, 130);
  tft.setTextDatum(5);
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.print("PPP TECH");
 

  taskBtnBegin();

    while (1)
    {
         
 
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


void touch_calibrate()
{
  uint16_t calData[5];
  uint8_t calDataOK = 0;

  // check file system exists
  if (!SPIFFS.begin()) {
    Serial.println("Formatting file system");
    SPIFFS.format();
    SPIFFS.begin();
  }

  // check if calibration file exists and size is correct
  if (SPIFFS.exists(CALIBRATION_FILE)) {
    if (REPEAT_CAL)
    {
      // Delete if we want to re-calibrate
      SPIFFS.remove(CALIBRATION_FILE);
    }
    else
    {
      File f = SPIFFS.open(CALIBRATION_FILE, "r");
      if (f) {
        if (f.readBytes((char *)calData, 14) == 14)
          calDataOK = 1;
        f.close();
      }
    }
  }

  if (calDataOK && !REPEAT_CAL) {
    // calibration data valid
    tft.setTouch(calData);
  } else {
    // data not valid so recalibrate
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(20, 0);
    tft.setTextFont(2);
    tft.setTextSize(1);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);

    tft.println("Touch corners as indicated");

    tft.setTextFont(1);
    tft.println();

    if (REPEAT_CAL) {
      tft.setTextColor(TFT_RED, TFT_BLACK);
      tft.println("Set REPEAT_CAL to false to stop this running again!");
    }

    tft.calibrateTouch(calData, TFT_MAGENTA, TFT_BLACK, 15);

    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.println("Calibration complete!");

    // store data
    File f = SPIFFS.open(CALIBRATION_FILE, "w");
    if (f) {
      f.write((const unsigned char *)calData, 14);
      f.close();
    }
  }
}


