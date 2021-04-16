#include"function.h"
#include<stdio.h>


void addToJournalEntry(){

    int temp;
    
    char dmy[9];
    char filename[13];
    char textInput[3000]="";
    printf("\nEnter the date of the entry in the format DDMMYYYY: ");
    
    scanf("%s",&dmy);
    sprintf(filename,"%s.txt",dmy);
    printf("%s",filename);
    FILE *filePointer; 
    filePointer = fopen(filename, "a");
    if(!filePointer){
        printf("\nFile doesn't exist!\n");
        return;
    }
    printf("\nEnter data to be Inputted: \n");
    scanf("%d",&temp);
    fgets(textInput, 3000, stdin);
    fputs(textInput, filePointer); 
    printf("\n____________________\n\nSuccessfully added the entry!\n____________________\n");
    fclose(filePointer);
}