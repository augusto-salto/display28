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


int RestServer::simpleRequest(String key, String value)
{
    
    //TODO
    String server_url = this->_server_name + this->_city_name + this->_country_code + this->_api_key;
    return getJsonRequest(server_url, key, value);

}

int RestServer::arrayRequest(String key, int index, String value)
{
    String server_url;

    if(this->_api_key.equals("") || this->_country_code.equals(""))
    {
        this->_server_name.trim();
        server_url = this->_server_name;
        server_url.trim();
       

    } else 
    {

        server_url = this->_server_name + this->_city_name + this->_country_code + this->_api_key;
        server_url.trim();
        
         
    }
    
    return getJsonRequest(server_url, key, value, index);
    
}

String RestServer::stringRequest(String key, String value)
{
    String server_url;

    if(this->_api_key.equals("") || this->_country_code.equals(""))
    {
        this->_server_name.trim();
        server_url = this->_server_name;
        server_url.trim();
       

    } else 
    {

        server_url = this->_server_name + this->_city_name + this->_country_code + this->_api_key;
        server_url.trim();
        
         
    }
    
    return getStringJsonRequest(server_url, key, value);
    
}