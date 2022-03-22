#include <ntp_lib.h>

WiFiUDP ntpUDP;
const long utcOffsetInSeconds = -10800; //GMT -3
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);



const String DIA_SEMANA[] = {"Dom", "Seg", "Ter", "Qua", "Qui", "Sex", "Sab"};
const String MES[] = {"Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out", "Nov", "Dez"};
int hora = 0;
int minuto = 0;

void initRelogio(){

    timeClient.begin();
    
}

String getTime()
{

timeClient.update();
return timeClient.getFormattedTime();

}

String getDate()
{   
    String date = "";


    timeClient.update();
    time_t epochTime = timeClient.getEpochTime();
    struct tm*ptm = gmtime ((time_t *)&epochTime);  

    

    int monthDay = ptm->tm_mday;

    
    date = monthDay;
    date = date + "/";
    

    int currentMonth = ptm->tm_mon+1;
    date = date + MES[currentMonth-1] + "/";
    

    int currentYear = ptm->tm_year+1900;
    date = date + currentYear;
   

    return date;
}