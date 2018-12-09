/* A program to print a histogram of the frequencies of different characters in its input. */
#include<stdio.h>
#define SIZE 52

void printStars(int);
void histogram(char key[], long data[], int length);
int main(){
	long count[SIZE];
	char key[SIZE], caps='A';
	int c;
	for (int i = 0; i < SIZE/2; ++i){
		key[i] = 'A'+i;
		key[i + SIZE/2] = 'a'+i;
		count[i]=0;
		count[i + SIZE/2]=0;
	}
	while((c = getchar()) != EOF){
		if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
			count[c-((((32&c) && caps)*('a'-26)) + (!((32&c)&&caps)*'A'))]++;
	}
	histogram(key,count, SIZE);
	return 0;
}
void histogram(char key[], long data[], int length){
	for(int i = 0; i < length; i++){
		putchar(key[i]);
		putchar(':');
		printStars(data[i]);
	}
}

inline void printStars(int count){
	for (int j = 0; j < count; ++j)
		putchar('*');
	putchar('\n');
}