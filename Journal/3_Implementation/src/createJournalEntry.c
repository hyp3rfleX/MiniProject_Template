#include"function.h"
#include<stdio.h>

void createJournalEntry(char *filename){
    int temp;
    char textInput[3000]="";
    FILE *filePointer; 
    filePointer = fopen(filename, "w");
    printf("\nEnter data to be Inputted: \n");
    scanf("%d",&temp);
    fgets(textInput, 3000, stdin);
    fputs(textInput, filePointer); 
    printf("\n____________________\n\nSuccessfully stored the entry!\n____________________\n");
    fclose(filePointer);
}