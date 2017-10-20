 #include <stdio.h>
#include "file.h"
int main() {
    printf("========Fang LI LAB3============\n");
     Mili_time time[6];
    time[0].Hour=1;
    time[0].Minute=30;
    time[0].Second=45;
    
    time[1].Hour=16;
    time[1].Minute=30;
    time[1].Second=45;
    
    time[2].Hour=0;
    time[2].Minute=01;
    time[2].Second=01;
    
    time[3].Hour=23;
    time[3].Minute=59;
    time[3].Second=59;
    
    time[4].Hour=12;
    time[4].Minute=00;
    time[4].Second=00;
    
    time[5].Hour=12;
    time[5].Minute=00;
    time[5].Second=00;
    Mili_time re;
    int i;
    printf("=========elapsed times for test\n");
    for(i=0;i<6;i=i+2)
    {
        re=sub(time[i], time[i+1]);
        printf("%02d:%02d:%02d-%02d:%02d:%02d||%02d:%02d:%02d\n",time[i].Hour,time[i].Minute,time[i].Second,time[i+1].Hour,time[i+1].Minute,time[i+1].Second,re.Hour,re.Minute,re.Second);
    }
     test[0].mon=1;
    test[0].day=19;
    test[0].year=1809;
    test[0].time.Hour=12;
    test[0].time.Minute=1;
    
    test[1].mon=11;
    test[1].day=11;
    test[1].year=1922;
    test[1].time.Hour=6;
    test[1].time.Minute=00;
    
    test[2].mon=1;
    test[2].day=6;
    test[2].year=2000;
    test[2].time.Hour=8;
    test[2].time.Minute=22;
    char *p[13]={"","January","February","March","April","May","June","July","August","September","October","November","December"};
    printf("=========struct DateTime \n");
    for(i=0;i<3;i++)
    {
        printf("%s  %d   %d   %d:%02d\n",p[test[i].mon],test[i].day,test[i].year,test[i].time.Hour,test[i].time.Minute);
    }
    return 0;
}

