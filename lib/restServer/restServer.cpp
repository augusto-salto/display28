#include <restServer.h>



void RestServer::setServerName(String server_name)
{
    this->_server_name = server_name;
}


void RestServer::setApiKey(String api_key)
{
    this->_api_key = api_key;
}


void RestServer::setCountryCode(String code)
{
    this->_country_code = code;
}


void RestServer::setCityName(String city_name)
{
    this->_city_name = city_name;
}


String RestServer::simpleRequest(char key, char value)
{
    //TODO
    String server_url = this->_server_name + this->_api_key;
    return getJsonRequest(server_url, key, value);
}
