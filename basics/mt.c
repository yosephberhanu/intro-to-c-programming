/*
 A program to display the Multiplication Table upto/for a given number
*/
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>

void multiTable(int);
int main(int argc, char* argv[])
{

	int input;
	if(argc<2){
		printf("Command Format\n\t %s <number>\n",argv[0] );
	}else{
		input = atoi(argv[1]);
		multiTable(input);
	}
	return 0;
}
void multiTable(int input)
{
	system("clear");
	for(int i = 1; i <= input; i++){
		for(int j = 1; j<= input; j++){
			printf("%3d ",i*j);
		}
		printf("\n");
	}
	getchar();
}