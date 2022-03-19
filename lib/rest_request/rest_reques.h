#ifndef REST_REQUEST_H
#define REST_REQUEST_H

    #include <Arduino_JSON.h>
    #include <HTTPClient.h>

String getJsonRequest(String url, char key, char value, int index);
String getJsonRequest(String url, char key, char value);
String httpGETRequest(const char* serverName);

#endif