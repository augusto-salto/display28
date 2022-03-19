#ifndef REST_SERVER_H
#define REST_SERVER_H

    #include <rest_reques.h>

class RestServer{

    public:
        void setServerName(String server_name);
        void setApiKey(String api_key);
        void setCountryCode(String code);
        void setCityName(String city_name);
        String simpleRequest(char key, char value);
        String arrayRequest(char key, int index, char value);

    private:
        String _server_name = "";
        String _api_key = "";
        String _country_code = "";
        String _city_name = "";
       


};


#endif