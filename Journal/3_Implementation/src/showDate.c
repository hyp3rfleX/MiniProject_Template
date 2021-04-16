#include"function.h"
#include<stdio.h>

void showDate(int day,int month,int year){
    //char dateShow[20];
    //sprintf(dateShow,"%02d/%02d/%04d",day, month+1, year+1900);
    printf("%02d/%02d/%04d",day, month+1, year+1900);
    return;
}