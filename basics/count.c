#include<stdio.h>
#define true 1
#define false 0
#define boolean char
int main(){
	int c;
	long charCount = 0, wordCount = 0, lineCount = 0;
	boolean whitespace = false, newline = false;
	
	while((c=getchar()) != EOF){
		charCount++;
		if((c!= ' ') && (c != '\t') && (c != '\n') ){
			whitespace = false;
		}else if(!whitespace && (c == ' ' || c == '\t' || c == '\n' )){
			wordCount++;
			whitespace = true;
		}
		
		if(c != '\n'){
			newline = false;
		}else if(!newline && c == '\n'){
			lineCount++;
			newline = true;
		}
	}
	
	printf("Character Count: %ld\n",charCount);
	printf("Word Count: %ld\n",wordCount);
	printf("Line Count: %ld\n",lineCount);
}