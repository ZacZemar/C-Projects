//Code for Zemar Robbins on Project 6 which puts the suffix in the file and concats them given a max size (20)

#include <stdio.h>
#include <string.h>


int M; //Creating global M variable
void read_file(FILE *pFile); //Declaring the function 
int main(int argc, char *argv[]){ //Will take command line arguments 
    printf("Enter the value of M = \n");
    scanf("%d", &M);

    for(int i = 1; i < argc; i++){ //Looping through all the command line arguments
        printf("%s: ", argv[i]);
        read_file(fopen(argv[i],"r"));
    }
    return 0;
}
void read_file(FILE *pFile){
    int curr_suffix = 0; //Starting the current suffix to be zero

    char input_word[21] = ""; 
    char suffix[1001] = "";

//create a while statement that reads a lone of text from a file (fgets)
    do{
        if(strlen(input_word) - 1 > M){ //If the len is greater than M than continue to the next
            continue;
        }
        if(strlen(input_word) - 1 > M - curr_suffix){
            strcpy(suffix, ""); //Give it a blank
        }
        strncat(suffix,input_word,strlen(input_word) - 1); //Then combine the two 

        curr_suffix = strlen(suffix);
    }while(fgets(input_word, 21, pFile) != NULL); //As long as it doesn't exceed 20 characters
    printf("%s\n", suffix);

//use fclose to close the file
    if(fclose(pFile) == EOF){ //Error checking the pFile
        printf("WRONG");

    }
}