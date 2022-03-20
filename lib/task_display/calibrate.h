#ifndef CALIBRATE_H
#define CALIBRATE_H

    #include <SPI.h>
    #include <FS.h>
    #include <LittleFS.h> 
    #include <task_btn_display.h>


    #define CALIBRATION_FILE "/TouchCalData3"
    #define REPEAT_CAL false





void calibrateTouch(TFT_eSPI &tft);
void deleteCalibration();



#endif