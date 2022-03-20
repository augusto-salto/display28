#include <task_tempo.h>


TaskHandle_t handle_tempo;

int temperature = 0;
int humidity = 0;
int rainPossibility = 0;
String dolarActualValue = "";
String euroActualValue = "";

RestServer temp;
RestServer hum;
RestServer rain;
RestServer euro;
RestServer dolar;

void taskTempo(void *pvParameters )
{
    
    configTemp();
    configHumidity();
    configRain();
    configEuro();
    configDolar();


    
    while (1)
    {
        temperature = temp.simpleRequest("main", "temp");
        xQueueOverwrite(xQueue_temp, (void *)&temperature);     
        Serial.print("\nTEMPERATURE: ");
        Serial.print(temperature);

        humidity = hum.simpleRequest("main", "humidity");
        xQueueOverwrite(xQueue_hum, (void *)&humidity);     
        Serial.print("\nHUMIDITY: ");
        Serial.print(humidity);

        rainPossibility = rain.arrayRequest("data", 0, "pop");
        xQueueOverwrite(xQueue_rain, (void *)&rainPossibility);     
        Serial.print("\nRAIN: ");
        Serial.print(rainPossibility);

        euroActualValue = euro.stringRequest("EURBRL", "ask");
        xQueueOverwrite(xQueue_rain, (void *)&euroActualValue);     
        Serial.print("\nEURO: ");
        Serial.print(euroActualValue);

        dolarActualValue = dolar.stringRequest("USDBRL", "ask");
        xQueueOverwrite(xQueue_rain, (void *)&dolarActualValue);     
        Serial.print("\nDOLAR: ");
        Serial.print(euroActualValue);

        

        vTaskDelay(pdMS_TO_TICKS(5000));
    }
    
}

void taskTempoBegin()
{
     xTaskCreate( taskTempo /* Funcao a qual esta implementado o que a tarefa deve fazer */
                  , "taskTempoDebug" /* Nome (para fins de debug, se necessário) */
                  , TASK_TEMPO_SIZE /* Tamanho da stack (em words) reservada para essa tarefa */
                  , NULL /* Parametros passados (nesse caso, não há) */
                  , 3 /* Prioridade */
                  , &handle_tempo ); /* Handle da tarefa, opcional */
}

void configTemp()
{
    temp.setServerName("http://api.openweathermap.org/data/2.5/weather?q=");
    temp.setCityName("Salto,");
    temp.setCountryCode("BR");
    temp.setApiKey("&APPID=235956c829097d66683370e461b8a8a5");
}

void configHumidity()
{
    hum.setServerName("http://api.openweathermap.org/data/2.5/weather?q=");
    hum.setCityName("Salto,");
    hum.setCountryCode("BR");
    hum.setApiKey("&APPID=235956c829097d66683370e461b8a8a5");  
}

void configRain()
{
    rain.setServerName("http://api.weatherbit.io/v2.0/forecast/daily?city=Salto,BR&key=4073b3678d3e456d97c63e438c1bc811&lang=pt&days=1");

}

void configEuro()
{
    euro.setServerName("http://economia.awesomeapi.com.br/last/USD-BRL,EUR-BRL,BTC-BRL");
}

void configDolar()
{
    dolar.setServerName("http://economia.awesomeapi.com.br/last/USD-BRL,EUR-BRL,BTC-BRL");
}