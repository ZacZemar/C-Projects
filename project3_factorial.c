// Lisa Patel U50140470 code for Factorial 
#include <stdio.h>
//list out the fucntions that will be called in the main afterwards
int fact (int n);
void calculate_fact(int a[], int n, int b[]);
int main(){
// initialize the variables 
    int n;//represents the size of the array

    printf("Enter the length of the array: \n");//print the length of the array
    scanf("%d", &n);

    int a[n];//represents the input array
    int b[n];//represents the output array
    int i;

    printf("Enter the elements of the array: \n");//print the elements of the array
    for(i = 0; i < n; i++){
        scanf("%d\n", &a[i]);
    }
    
    calculate_fact(a, n, b);//call function

    printf("Output: \n");//print output of the factorials
    for(i = 0; i < n; i++){
        printf("%d\n", b[i]);
    }
    return 0;
}
int fact(int n){//include the recursive factorial function
    if (n <= 1){
        return 1;
    }
    else{    
        return n * fact(n-1);
    }
}
void calculate_fact(int a[], int n, int b[]){//this function refers to how to calculate the factorials 
    int i;
    for(i = 0;i < n; i++){
        b[i] = fact(a[i]);
    }
}
//code completed