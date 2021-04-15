#include<stdio.h>
#include<time.h>

void showDate(int day,int month,int year){
    //char dateShow[20];
    //sprintf(dateShow,"%02d/%02d/%04d",day, month+1, year+1900);
    printf("%02d/%02d/%04d",day, month+1, year+1900);
    return;
}

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