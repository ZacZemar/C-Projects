/* Name: Zemar                 *
 * NetID: zrobbins1                                *
 * Description: this code contains my solution for *
 *              the sixth project of COP3514.002   */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define THOUSAND 1000
int wetperimeter(char matrix[THOUSAND][THOUSAND], int R, int C);

int main(int argc, char *argv[]){

	int R, C; //Creating the Rows and Columns

	char matrix[THOUSAND][THOUSAND]; //The matrix that is no more than 1000
	FILE *fp = fopen(argv[1], "r");

	do {
		matrix[R][C];
	} while((fscanf(fp, "%d%d", &R, &C)) == 2);


	FILE *fc; //Creating the file pointer 
	FILE *s; //Creating the file pointer

	if((R < 1 || R > 1000) && (C < 1 || C > 1000)){
        printf("Error with the rows and columns");
	}
	int AREA = R * C;
	char temp[R];

	if (fp == NULL){
		printf("Error number 1\n");
		return 1;
	}

	int i = 0, j = 0;

	while(!feof(fp) && !ferror(fp)){ //CHECKING THE MATRIX AND SETTING TO TEMP AS LONG AS ITS NOT EOF OR NO ERRORS
		for(i = 0; i < R; i++){
			fscanf(fp, "%[^\n]\n", temp);
			for(j = 0; j < C; j++){
				matrix[i][j] = temp[j];
			}
		}
	}


	int Land_Counter; //COUNTING THE LAND
	char coast[R][C]; //ROW COLOUMN FOR THE COAST


	for(int Z = 0; Z < R; Z++){
		for(int Q = 0; Q < C; Q++){
			if(matrix[Z][Q] == 'L'){
				Land_Counter+=1;
			}
			if(((Z) != (R - 1)) && (Z != 0) && ((Q) != (C - 1)) && (Q != 0)){
				if((matrix[Z][Q+1] == 'L') && ((matrix[Z][Q-1] == 'L') && (matrix[Z+1][Q] == 'L') && (matrix[Z-1][Q] == 'L'))){
					coast[Z][Q] = 'N';
				}
				else{
					if(matrix[Z][Q] == 'L'){
						coast[Z][Q] = 'Y';
					}
					if(matrix[Z][Q] == 'W'){
						coast[Z][Q] = 'N';
					}
				}
			}
			else if(matrix[Z][Q] == 'L')
				coast[Z][Q] = 'Y';
			else if(matrix[Z][Q] == 'W')
				coast[Z][Q] = 'N';
		}
	}

	int WP = wetperimeter(matrix, R, C); //Callback to the wet perimeter function

	fc = fopen("coast.txt", "w");
	if (fc == NULL) //Checking to see if its NULL or not
	{
		printf("Error number 2\n");
		return 2;
	}
	int Q, V;
	for(Q = 0; Q < R; Q++){
		for(V = 0; V < C; V++){
			fprintf(fc, "%c", coast[Q][V]);
		}
		fprintf(fc,"\n");
	}
	fclose(fc); //Closing the file

	s = fopen("statistics.txt", "w"); //Opening the statistics file with write permissions
	if (s == NULL){
		printf("Error number 3\n");
		return 3;
	}

	fprintf(s, "TOTAL AREA: %d\n", AREA);
	fprintf(s, "TOTAL LAND AREA: %d\n", Land_Counter);
	fprintf(s, "WET PERIMETER: %d\n", WP);
	fclose(s);

	fclose(fp); //Closing the file
	return 0;
}

int wetperimeter(char matrix[THOUSAND][THOUSAND], int R, int C){ //Function definition of wet perimeter
	int U, O, WP;
	int toret; //return 
	for(U = 0; U < R; U++){
		for(O = 0; O < C; O++){
			if(matrix[U][O] == 'L'){ //Looping the indexes to see L and W whether to increment the Wet Perimeter
				if(matrix[U][O+1] == 'W'){
					WP+=1;
				}
				if(matrix[U][O-1] == 'W'){
					WP+=1;
				}
				if(matrix[U+1][O] == 'W'){
					WP+=1;
				}
				if(matrix[U-1][O] == 'W'){
					WP+=1;
				}
				if(U==0){
					WP+=1;
				}
				if(O==0){
					WP+=1;
				}
				if(U==(R-1)){
					WP+=1;
				}
				if(O==(C-1)){
					WP+=1;
				}
			}
		}
	}
	toret = WP; //The return is equal to the wet perimeter
	return toret; //Returning the to return
}
