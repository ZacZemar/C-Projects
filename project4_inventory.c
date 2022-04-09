//Code for Zemar Robbins U03712676

#include <stdio.h>
//fucntion declaration 
int find_minimum(int *a, int n);

int main(){
    int num_parts; //Declaring these variables 
    int num_part_types;
    int list_part;

    printf("Enter number of parts (N): \n"); //Asking user to input parts
    scanf("%d", &num_parts); 
   
    if(1000000 < num_parts || 1 > num_parts){ //If within these parameters then its invalid
        printf("Invalid number of parts %d\n", num_parts); 
        printf("Must be in the range [1,1000000]\n"); 
        return 0;
    }

    printf("Enter number of part types (K): \n"); //Allow user to enter the part types
    scanf("%d", &num_part_types); 

    if(10000 < num_part_types || 1 > num_part_types){ //If within these parameters then its invalid
        printf("Invalid number of parts %d\n", num_part_types); 
        printf("Must be in the range [1,10000]\n");
        return 0;
    }

    int *p; //Make a pointer variable 
    int a[num_part_types]; //delare the array of size num part types

    for(p = a; p < a + num_part_types; p++){ //Loop through to make it zero
        *p = 0;
    }

    printf("Enter part list: \n");
    for(int i = 0; i < num_parts; i++){ //Looping the part list then subtracting one from the value to one to the address
        scanf("%d", &list_part);
        
        a[list_part - 1] = a[list_part - 1] + 1;
    }

    if(1000 < list_part || 1 > list_part){ //If within these parameters then its invalid
        printf("Invalid list of parts.\n");
        printf("Part codes must be in the range [1,2]\n");
        return 0;
    }
    
    int min = find_minimum(a, num_part_types); //Declaring min


    printf("The factory can build %d computer(s).\n", min );

    return 0;
}
int find_minimum(int *a, int n){ //Function that makes the mininum to the pointer
    int *p;
    int minimum = *a;

    for (p = a; p < a + n; p++){ //Loop through to find the minimum
        if (minimum > *p){
            minimum = *p;
        }
    }
    return minimum;
}