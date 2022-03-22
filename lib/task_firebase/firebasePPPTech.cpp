#include <firebasePPPTech.h>

#include <FirebaseESP32.h>
#include <string>

#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config; 
    

FireBaseClass::FireBaseClass(){

    config.api_key = API_KEY;
    auth.user.email = USER_EMAIL;
    auth.user.password = USER_PASSWORD;
    config.database_url = DATABASE_URL;
    config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h
    Firebase.begin(&config, &auth);
   
}



int FireBaseClass::getTotal()
{

        if(Firebase.ready())
        {

            Firebase.getInt(fbdo, "/real/volumeTotal");
            return fbdo.intData();

        }else
        {
            return 0;
        }
}



float FireBaseClass::getVazao()
{

        if(Firebase.ready())
        {

            Firebase.getFloat(fbdo, "/real/vazaoInstantanea");
            return fbdo.floatData();

        }else
        {
            return 0;
        }

}



int FireBaseClass::getNivel()
{
         if(Firebase.ready())
         {
            Firebase.getString(fbdo, "/real/nivel");
            return fbdo.stringData().toInt();
        }else
        {
            return 0;
        }
}


