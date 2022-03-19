#include <rest_reques.h>

String jsonBuffer;

String getJsonRequest(String url, char key, char value, int index)
{
    String retorno;
    //String api_key = "5eb696d297c74a53bc73a4edb24619ab  ";
    //String server = "http://api.weatherbit.io/v2.0/forecast/daily?city=Salto,BR&key=4073b3678d3e456d97c63e438c1bc811&lang=pt&days=1";
    jsonBuffer = httpGETRequest(url.c_str());
    JSONVar myObject2 = JSON.parse(jsonBuffer);
    
        if (JSON.typeof(myObject2) == "undefined") 
        {
            return "NULL";
        }

        
        retorno = myObject2[key][index][value];
        return retorno;
        
}   // end getJsonRequest

String getJsonRequest(String url, char key, char value)
{
    String retorno;
    //String api_key = "5eb696d297c74a53bc73a4edb24619ab  ";
    //String server = "http://api.weatherbit.io/v2.0/forecast/daily?city=Salto,BR&key=4073b3678d3e456d97c63e438c1bc811&lang=pt&days=1";
    jsonBuffer = httpGETRequest(url.c_str());
    JSONVar myObject2 = JSON.parse(jsonBuffer);
    
        if (JSON.typeof(myObject2) == "undefined") 
        {
            return "NULL";
        }

        retorno = myObject2[key][value];
        return retorno;
        
}   // end getJsonSimpleRequest



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