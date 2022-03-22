#include <main.h>
#include <LittleFS.h> 
#include <TFT_eSPI.h> 



void setup() 
  {
   
    Serial.begin(115200);
    WiFi.begin("NINO", "ra201291");

    Serial.print("CONECTANDO");

    while (WiFi.status() != WL_CONNECTED)
    {
      Serial.print(".");
      vTaskDelay(pdMS_TO_TICKS(500));
    }

    // INICIALIZAÇÃO DO RECURSOS DO FREERTOS
    initializeQueue();
    initializeSemaphore();

    // INICIALIZAÇÃO DAS TAREFAS AUXILIARES
    taskTempoBegin();

    // INICIALIZAÇÃO DO RELOGIO
    taskNtpBegin();
    taskFirebaseBegin();
    // INICIALIZAÇÃO DO DISPLAY
    taskDisplayBegin();


  } //end setup


void loop() 
  {
     vTaskDelay(pdMS_TO_TICKS(10));
  } // end loop




void initializeQueue()
{

  xQueue_temp = xQueueCreate( 1, sizeof( int ) );
  xQueue_hum = xQueueCreate( 1, sizeof( int ) );
  xQueue_rain = xQueueCreate( 1, sizeof( int ) );
  xQueue_nivel = xQueueCreate( 1, sizeof( int ) );
  xQueue_dolar = xQueueCreate( 1, sizeof( float ) );
  xQueue_euro = xQueueCreate( 1, sizeof( float ) );
  xQueue_time = xQueueCreate( 1, sizeof( String ) );
  xQueue_btn = xQueueCreate( 1, sizeof( u8_t ) );
  xQueue_casos_covid = xQueueCreate( 1, sizeof( int ) );;
  xQueue_mortes_covid = xQueueCreate( 1, sizeof( int ) );;
  xQueue_notice = xQueueCreate( 1, sizeof( String ) );
  xQueue_currentDate = xQueueCreate( 1, sizeof( String ) );
  xQueue_currentHours = xQueueCreate( 1, sizeof( String ) );
  xQueue_nivel = xQueueCreate( 1, sizeof( int ) );;
  xQueue_total = xQueueCreate( 1, sizeof( int ) );;
  xQueue_vazao = xQueueCreate( 1, sizeof( float ) );;

}

void initializeSemaphore()
{
  xSerial_http_request = xSemaphoreCreateMutex();
  xTft_semaphore = xSemaphoreCreateMutex();
}
 
