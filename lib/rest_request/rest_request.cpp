#include <rest_reques.h>


String jsonBuffer;

int getJsonRequest(String url, String key, String value, int index)
{
    int retorno;
    //String api_key = "5eb696d297c74a53bc73a4edb24619ab  ";
    //String server = "http://api.weatherbit.io/v2.0/forecast/daily?city=Salto,BR&key=4073b3678d3e456d97c63e438c1bc811&lang=pt&days=1";
    jsonBuffer = httpGETRequest(url.c_str());
    JSONVar myObject2 = JSON.parse(jsonBuffer);
    
        if (JSON.typeof(myObject2) == "undefined") 
        {
            return 0;
        }

        
        retorno = myObject2[key.c_str()][index][value.c_str()];
        return retorno;
        
}   // end getJsonRequest

int getJsonRequest(String url, String key, String value)
{
    
    int retorno;
    
    //String api_key = "5eb696d297c74a53bc73a4edb24619ab  ";
    //String server = "http://api.weatherbit.io/v2.0/forecast/daily?city=Salto,BR&key=4073b3678d3e456d97c63e438c1bc811&lang=pt&days=1";
    jsonBuffer = httpGETRequest(url.c_str());
    JSONVar myObject2 = JSON.parse(jsonBuffer);
    
        if (JSON.typeof(myObject2) == "undefined") 
        {

            Serial.print("\n UNDEFINED: ");
 
            return 0;

        }


        retorno = myObject2[key.c_str()][value.c_str()];
        
        if(value.equals("temp")){
            return retorno - 273;
        }else{
            return retorno;
        }
    
       
        
}   // end getJsonSimpleRequest

String getStringJsonRequestHTTPS(String url, String key, String value)
{
    String retorno;
    jsonBuffer = httpSGETRequest(url.c_str());
    JSONVar myObject2 = JSON.parse(jsonBuffer);
    
    /*Serial.print("JSONVARbuff");
    Serial.print(jsonBuffer);
    Serial.print("\n");*/
    
        if (JSON.typeof(myObject2) == "undefined") 
        {
            Serial.print("JSON INDEFINIDO!");
            return "NULL";
        }

        
        retorno = myObject2[key.c_str()][value.c_str()];
        return retorno;
        
}  

String getStringJsonRequestHTTPS(String url, String key, String value, int index)
{
    String retorno;
    jsonBuffer = httpSGETRequest(url.c_str());
    JSONVar myObject2 = JSON.parse(jsonBuffer);
    
    /*Serial.print("JSONVARbuff");
    Serial.print(jsonBuffer);
    Serial.print("\n");*/
    
        if (JSON.typeof(myObject2) == "undefined") 
        {
            Serial.print("JSON INDEFINIDO!");
            return "NULL";
        }

        
        retorno = myObject2[key.c_str()][index][value.c_str()];
        return retorno;
        
}  

int getIntJsonRequestHTTPS(String url, String key, String value)
{
    int retorno;
    jsonBuffer = httpSGETRequest(url.c_str());
    JSONVar myObject2 = JSON.parse(jsonBuffer);
    
    /*Serial.print("JSONVARbuff");
    Serial.print(jsonBuffer);
    Serial.print("\n");*/
    
        if (JSON.typeof(myObject2) == "undefined") 
        {
            Serial.print("JSON INDEFINIDO!");
            return 0;
        }

        
        retorno = myObject2[key.c_str()][value.c_str()];
        return retorno;
        
}  



String httpGETRequest(const char* serverName) 
{
    WiFiClient client;
    HTTPClient http;
  
    http.begin(client, serverName);
    int httpResponseCode = http.GET();
    String payload = "{}"; 
  
        if (httpResponseCode>0) 
        {

            payload = http.getString();

        }else 
        {

        }

        http.end();

        return payload;

}   // end httpGETRequest

String httpSGETRequest(const char* serverName) 
{
    WiFiClientSecure client;
    HTTPClient http;
    
    client.setInsecure();
    http.begin(client, serverName);
    int httpResponseCode = http.GET();
    String payload = "{}"; 
  
        if (httpResponseCode>0) 
        {

            payload = http.getString();

        }else 
        {

        }

        http.end();

        return payload;

}  