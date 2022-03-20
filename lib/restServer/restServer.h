#ifndef REST_SERVER_H
#define REST_SERVER_H

    #include <rest_reques.h>

    #define APPID "&APPID="

class RestServer{

    public:
        void setServerName(String server_name);
        void setApiKey(String api_key);
        void setCountryCode(String code);
        void setCityName(String city_name);
        int simpleRequest(String  key, String value);
        int arrayRequest(String key, int index, String value);
        String stringRequest(String key, String value); 

    private:
        String _server_name = "";
        String _api_key = "";
        String _country_code = "";
        String _city_name = "";
       


};


#endif