#include"function.h"
#include<stdio.h>



void readJournalEntry(){
    char dmy[9];
    char filename[13];
    char textInput[3000]="";
    printf("\nEnter the date of the entry in the format DDMMYYYY: ");
    scanf("%s",&dmy);
    sprintf(filename,"%s.txt",dmy);
    FILE *filePointer; 
    filePointer = fopen(filename, "r");
    if(!filePointer){
        printf("\nFile doesn't exist!\n");
        return;
    }
    printf("The file reads:\n\n\n___________________________________\n\n\n\n\n\n\n\n");
    while( fgets( textInput, 3000, filePointer) != NULL )
    {
        printf( "%s" , textInput );
    }
    printf("\n\n\n\n\n\n___________________________________\n\n");
    fclose(filePointer);
}