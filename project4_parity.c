// Zemar Robbins U03712676 Code 
#include <stdio.h>

void find_parity(int *a, int n, int *all_even, int *all_odd); //function declaration 
int main(){
    int n; //represents the size of the array
    int all_odd = 0;
    int all_even = 0;

    printf("Enter the length of the array: \n"); //print the length of the array
    scanf("%d", &n);
    
    int a[n]; //Array with size n 
    int *p; //Declaring the pointer 

    printf("Enter the elements of the array: \n"); 

    for(p = a; p < a + n; p++){ //Loop through the array to allow user to type it 
        scanf("%d", &(*p));
    }

    find_parity(a, n, &all_even, &all_odd); //Function call

     printf("Output: ");
    if (all_even == 0){
        if(all_odd == 1) //If it meets the conditions then odd
            printf("Good, all elements are odd. \n");
    }
    if (all_even == 1)
        if(all_odd == 0)//If it meets the conditions then even
            printf("Good, all elements are even. \n");
    else
        printf("Not good. \n");

    return 0;
}
void find_parity(int *a, int n, int *all_even, int *all_odd){ //Function to determine if its even or if its odd
    int *p; //Declare pointer
    for(p = a; p < a + n; p++){ //Loop through the array to determine if its all odd or even to be 1
        if (*(p) - (*(p) / 2) * 2 == 1){
            *all_odd = 1;
        }
        if (*(p) - (*(p) / 2) * 2 == 0){
            *all_even = 1;
        }

    }
}