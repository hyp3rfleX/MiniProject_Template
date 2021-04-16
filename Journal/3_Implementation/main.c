#include<stdio.h>
#include<time.h>
#include "function.h"


int main(){
    int choice,temp;

    time_t T= time(NULL);
    struct  tm tm = *localtime(&T);

    char fname[13];

    sprintf(fname,"%02d%02d%04d.txt",tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    
    printf("\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n\n\nWelcome to your Journal. \n\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n\n\n");
    a:
    printf("What would you like to do?\n\n\n1) Create new Journal Entry for Today (");
    showDate(tm.tm_mday, tm.tm_mon, tm.tm_year);
    printf(")\n2) Add to existing Journal Entry\n3) Read existing Journal Entry\n4) Exit\n\n\nYour Choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            createJournalEntry(fname);
            goto a;
            break;
        case 2:
            addToJournalEntry();
            goto a;
            break;
        case 3:
            readJournalEntry();
            goto a;
            break;
        default:
            break;
    } 
}

//tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900
//showDate(tm.tm_mday, tm.tm_mon, tm.tm_year);
//printf("%s",fname);