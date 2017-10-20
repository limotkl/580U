
#include "file.h"

Mili_time sub(Mili_time time1,Mili_time time2){
    int Stime1= numSeconds(time1);
    int Stime2= numSeconds(time2);
    int subtime=(Stime1-Stime2)>0?(Stime1-Stime2):(Stime2-Stime1);
    Mili_time result;
    result.Second=subtime%SECONDS_IN_A_MINUTE;
    result.Minute=(subtime/SECONDS_IN_A_MINUTE)%MINUTES_IN_AN_HOUR;
    result.Hour=subtime/SECONDS_IN_A_MINUTE/MINUTES_IN_AN_HOUR;
    return result;
}

int numSeconds(Mili_time time){ TRACE
    int Nmin;
    int Nsec;
    Nmin=time.Hour*MINUTES_IN_AN_HOUR+time.Minute;
    Nsec=Nmin*SECONDS_IN_A_MINUTE+time.Second;
    return Nsec;
    
}
