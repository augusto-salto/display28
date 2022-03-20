#ifndef REST_REQUEST_H
#define REST_REQUEST_H

    #include <Arduino_JSON.h>
    #include <HTTPClient.h>

int getJsonRequest(String url, String key, String value, int index);
int getJsonRequest(String url, String key,  String value);
String getStringJsonRequestHTTPS(String url, String key, String value);
int getIntJsonRequestHTTPS(String url, String key, String value);
String httpGETRequest(const char* serverName);
String httpSGETRequest(const char* serverName); 

#endif