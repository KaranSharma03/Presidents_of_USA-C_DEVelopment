/*
Author: Karan Sharma
Date: October 11, 2020.
Project Details: A console application built using structure arrays which prints information about the presidents
                 of the USA and swaps info and displays it again. It also prints the same information on a .txt file.
                 In this project, I have also created my own header file.
*/

#include "THE_HEADER_FILE.h"

FILE *fileHandle;

void printInfoInFILE(struct person p[]){
    fprintf(fileHandle,"The Presidents:");
    fprintf(fileHandle,"\n");
    for(int i=0;i<4;i++){
        fprintf(fileHandle,"\nName: %s, Took Office on date: %d/%d/%d\n", p[i].name,p[i].tookoffice.day, p[i].tookoffice.month, p[i].tookoffice.year);
    }
    fprintf(fileHandle,"\n");
}


void printInfo(struct person p[]){
    puts("The Presidents:");

    for(int i=0;i<4;i++){
        printf("Name: %s, Took Office on date: %d/%d/%d\n", p[i].name,p[i].tookoffice.day, p[i].tookoffice.month, p[i].tookoffice.year);
    }
    puts("\n");
}

void retry(){
    char choice;
    int deletes;

    puts("\n\nWould you like to print same data on a .txt file?");
	puts("#Press 'y' for printing the same data on a .txt file.");
	printf("#Press 'n' to exit.\n#");
	scanf(" %c", &choice);

	if(choice=='y'){
        puts("Data printed to a txt file");
	}
	else{
        deletes = unlink("output.txt");
        if(deletes==0){
            puts("Exiting now!");
            return 1;
        }
        else{
            puts("Failed to exit! Retry!");
            retry();
        }
	}
}

int main(){
    system("clear");

    /* open/create the file */
	fileHandle = fopen("output.txt","w");
	if( fileHandle == NULL )
	{
		puts("Failed to create file");
		return 1;
	}

    struct person presidents[]={
        { "George Washington", { 30, 4, 1789 } },
		{ "Thomas Jefferson", { 4, 3, 1801 } },
		{ "Abraham Lincoln", { 4, 3, 1861 } },
		{ "Theodore Roosevelt", { 14, 9, 1901 } }
    };

    struct person temp;

    printInfo(presidents);
    printInfoInFILE(presidents);
    Sleep(1500);

    temp = presidents[1];
    presidents[1] = presidents[2];
    presidents[2] = temp;
    puts("After Swapping the info:");
    fprintf(fileHandle,"After Swapping the info:\n");
    Sleep(1500);
    printInfo(presidents);
    printInfoInFILE(presidents);

    /* close the file */
	fclose(fileHandle);

	retry();

    return 0;
}
