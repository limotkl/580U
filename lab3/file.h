#ifndef file_h
#define file_h
#include <stdio.h>
#define SECONDS_IN_A_MINUTE 60
#define	MINUTES_IN_AN_HOUR 60
#define TRACE printf("numSeconds() at line:%d,in file.c\n",__LINE__);

enum mounths {January=1,February,March,April,May,June,July,August,September,October,November,December};
//char *p[13]={" ","January","February","March","April","May","June","July","August","September","October","November","December"};
typedef struct Time
{
    int Hour;
    int Second;
    int Minute;
    
}Mili_time;

struct DataTime
{
    Mili_time time;
    enum mounths mon;
    int day;
    int year;
}test[2];

Mili_time sub( Mili_time time1, Mili_time time2);

int numSeconds(Mili_time time);


#endif /* file_h */
