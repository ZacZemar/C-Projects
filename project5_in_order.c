#include <stdio.h>
#include <string.h>
#include <ctype.h>

int valid(char *word){
    // this is a helper function that will check if the input is valid
    // by checking if the letters are in the alphabet
    // acts as a boolean, if its valid returns 1, else 0
    int flag;
    char *ch;
    for(ch = word; *ch!='\0';ch++){
        if(isalpha(*ch)){
            flag = 1;
        }
        else
        {
            flag = 0;
            break; // breaks and ends as soon as its invalid
        }
    }
    return flag;
}

int inOrder(char *word){
    int flag = 1; 
    char *ch;

    if(valid(word)==0){
        flag = 0; // if invalid, returns 0
    }
    else{
        for(ch=word;*ch!='\0';ch++){
                *ch = tolower(*ch); // set it to lower for ease
                if((*ch < *(ch+1)) || (*ch == *(ch+1))){ // if first character is lower than the next or equal
                    // printf("1 in %c %c\n", *ch, *(ch+1)); // testing
                }
                else{
                    if((*(ch+1)!='\0') && (*ch > *(ch+1))){ // if the next char is not null and if the one before it is greater than its not in order
                        flag = 0;
                        break; // breaks as soon as its 0
                    }
                }
            }
    }

    return flag;
}

int main(int argc, char *argv[]){
    
    if(argc!=2){ // checks if its correct number of arguments
        printf("Incorrect number of arguments. Usage: ./a.out word");
        return 0;
    }

    if(inOrder(argv[1])){
        printf("It's in order");
    }
    else{
        printf("Not in order");
    }
    
    return 0;
}