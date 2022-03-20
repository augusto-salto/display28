#include <task_tempo.h>


TaskHandle_t handle_tempo;

int temperature = 0;
int humidity = 0;
int rainPossibility = 0;
String dolarActualValue = "";
String euroActualValue = "";
float floatDolar = 0;
float floatEuro = 0;
int casosCovid = 0;
int mortesCovid = 0;

RestServer temp;
RestServer hum;
RestServer rain;
RestServer euro;
RestServer dolar;
RestServer covid;
RestServer coin;

void taskTempo(void *pvParameters )
{
    
    configTemp();
    configHumidity();
    configRain();
    configCoin();
    configCovid();


    
    while (1)
    {
        // ACTUAL CLIMATE
        temperature = temp.simpleRequest(KEY_CLIMATE, VALUE_TEMP);
        xQueueOverwrite(xQueue_temp, (void *)&temperature);     
        Serial.print("\n\nTEMPERATURE: ");
        Serial.print(temperature);

        humidity = temp.simpleRequest(KEY_CLIMATE, VALUE_HUM);
        xQueueOverwrite(xQueue_hum, (void *)&humidity);     
        Serial.print("\nHUMIDITY: ");
        Serial.print(humidity);

        // RAIN PROBABILITY
        rainPossibility = rain.arrayRequest(KEY_RAIN, INDEX_RAIN, VALUE_RAIN);
        xQueueOverwrite(xQueue_rain, (void *)&rainPossibility);     
        Serial.print("\nRAIN: ");
        Serial.print(rainPossibility);

        // COIN 
        euroActualValue = coin.stringRequest(KEY_EURO, VALUE_EURO);
        floatEuro = euroActualValue.toFloat();
        xQueueOverwrite(xQueue_rain, (void *)&floatEuro);     
        Serial.print("\n\nEURO: ");
        Serial.print(floatEuro);

        dolarActualValue = coin.stringRequest(KEY_DOLAR, VALUE_DOLAR);
        floatDolar = dolarActualValue.toFloat();
        xQueueOverwrite(xQueue_rain, (void *)&floatDolar);     
        Serial.print("\nDOLAR: ");
        Serial.print(floatDolar);

        // COVID
        casosCovid = covid.intHTTPSRequest(KEY_COVID, VALUE_CASOS);
        xQueueOverwrite(xQueue_casos_covid, (void *)&casosCovid);   
        Serial.print("\n\nCASOS COVID: ");
        Serial.print(casosCovid);
        
        mortesCovid = covid.intHTTPSRequest(KEY_COVID, VALUE_DEATHS);
        xQueueOverwrite(xQueue_mortes_covid, (void *)&mortesCovid); 
        Serial.print("\nMORTES COVID: ");
        Serial.print(mortesCovid);
        

        vTaskDelay(pdMS_TO_TICKS(10000));
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

void configCoin()
{
    coin.setServerName("https://economia.awesomeapi.com.br/last/USD-BRL,EUR-BRL,BTC-BRL");
    
}



void configCovid()
{
    covid.setServerName("https://covid19-brazil-api.vercel.app/api/report/v1/brazil");
    
}