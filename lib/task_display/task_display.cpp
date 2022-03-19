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

  // Set the rotation before we calibrate
  tft.setRotation(1);

  // call screen calibration
  touch_calibrate();

  // clear screen
  tft.fillScreen(TFT_BLUE);
  tft.setCursor(110, 140);
  tft.setTextSize(2);
  tft.print("OLA MUNDO!");
  // Draw button (this example does not use library Button class)
  redBtn();
  

    while (1)
    {
         uint16_t x, y;

  // See if there's any touch data for us
  if (tft.getTouch(&x, &y))
  {
    Serial.print("\nCOORDENADA X: ");
    Serial.print(x);
    Serial.print("\nCOORDENADA Y: ");
    Serial.print(y);
    Serial.print("\n");

    // Draw a block spot to show where touch was calculated to be
    #ifdef BLACK_SPOT
      tft.fillCircle(x, y, 2, TFT_BLACK);
    #endif
    
    if (SwitchOn)
    {
      if ((x > REDBUTTON_X) && (x < (REDBUTTON_X + REDBUTTON_W))) {
        if ((y > REDBUTTON_Y) && (y <= (REDBUTTON_Y + REDBUTTON_H))) {
          Serial.println("Red btn hit");
          redBtn();
        }
      }
    }
    else //Record is off (SwitchOn == false)
    {
      if ((x > GREENBUTTON_X) && (x < (GREENBUTTON_X + GREENBUTTON_W))) {
        if ((y > GREENBUTTON_Y) && (y <= (GREENBUTTON_Y + GREENBUTTON_H))) {
          Serial.println("Green btn hit");
          greenBtn();
        }
      }
    }

    //Serial.println(SwitchOn);

  }
        

 
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

void drawFrame()
{
  tft.drawRect(FRAME_X, FRAME_Y, FRAME_W, FRAME_H, TFT_BLACK);
}

// Draw a red button
void redBtn()
{
  tft.fillRect(REDBUTTON_X, REDBUTTON_Y, REDBUTTON_W, REDBUTTON_H, TFT_RED);
  tft.fillRect(GREENBUTTON_X, GREENBUTTON_Y, GREENBUTTON_W, GREENBUTTON_H, TFT_DARKGREY);
  drawFrame();
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setTextDatum(MC_DATUM);
  tft.drawString("ON", GREENBUTTON_X + (GREENBUTTON_W / 2), GREENBUTTON_Y + (GREENBUTTON_H / 2));
  SwitchOn = false;
}

// Draw a green button
void greenBtn()
{
  tft.fillRect(GREENBUTTON_X, GREENBUTTON_Y, GREENBUTTON_W, GREENBUTTON_H, TFT_GREEN);
  tft.fillRect(REDBUTTON_X, REDBUTTON_Y, REDBUTTON_W, REDBUTTON_H, TFT_DARKGREY);
  drawFrame();
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setTextDatum(MC_DATUM);
  tft.drawString("OFF", REDBUTTON_X + (REDBUTTON_W / 2) + 1, REDBUTTON_Y + (REDBUTTON_H / 2));
  SwitchOn = true;
}
