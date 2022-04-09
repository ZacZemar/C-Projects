#include <stdio.h>
#include <stdlib.h>

int main(){

    char x[1000] = ""; // string obtained by user
    int len = 0; // length of x
    int esum=0; // sum of all even positioned numbers
    int osum=0; // sum of all odd positioned numbers

    printf("Enter the value of X: \n");
    scanf("%s", x);
    // printf("%s",x);
    char *p; // to iterate through string and find length
    for(p = x; *p!='\0';p++){
        // finds the length
        len+=1;
    }
    // printf("%d\n",len);
    for(p = x; *p!='\0'; p++)
    {
        // printf("%s\n",p);
        // checks if index is even or odd. Adds to esum if even, osum if odd.
        if(len%2==0){
            esum += (*p-'0');
        }
        else{
            osum += (*p-'0');
        }
        len+=1;
    }
    int difference = esum - osum; // difference between esum and osum
    if ((difference)%11){
        printf("%s is not a multiple of 11\n", x);
    }
    else{
        printf("%s is a multiple of 11\n", x);
    }
    return 0;
}

