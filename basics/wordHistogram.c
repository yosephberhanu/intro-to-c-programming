/* 
	A program to print a histogram of the lengths of words in its input. 
	to change the maximum word length supported update the value of MAX below
*/
#include<stdio.h>
#define MAX 55
int readWord(char buffer[]);
void printHistogram(long []);
void printStars(int);

int main(){
	long count[MAX];
	char buffer[MAX];
	for (int i = 0; i < MAX; ++i) count[i] = 0;
	
	int len;
	while((len = readWord(buffer)) >= 0){
		if(len == 0)continue;
		if(len > count[0]) count[0] = len;
		count[len]++;
	}
	printHistogram(count);
	return 0;
}
int readWord(char buffer[]){
	int returnValue = 0;
	int c;
	//	while((c=getchar())!=EOF && ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))){
	while((c=getchar())!=EOF && c !=' ' && c !='\t' && c !='\n' )
		buffer[returnValue++] = c;
	
	if(returnValue == 0 && c == EOF) returnValue = -1;
	
	return returnValue;
}
void printHistogram(long count[]){
	for (int i = 1; i <= count[0]; ++i)
	{
		printf("%d:",i);
		printStars(count[i]);
	}
}

inline void printStars(int count){
	for (int j = 0; j < count; ++j)
		putchar('*');
	putchar('\n');
}