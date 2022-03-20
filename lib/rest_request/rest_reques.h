#ifndef REST_REQUEST_H
#define REST_REQUEST_H

    #include <Arduino_JSON.h>
    #include <HTTPClient.h>

int getJsonRequest(String url, String key, String value, int index);
int getJsonRequest(String url, String key,  String value);
String getStringJsonRequest(String url, String key, String value);
String httpGETRequest(const char* serverName);

#endif