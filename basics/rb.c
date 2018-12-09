#include<stdio.h>
#define true 1
#define false 0
#define boolean char
/*
	Replace multiple white spaces with a single white space
*/

int main(){
	int c;
	boolean whitespace = false, newline = false;

	while((c = getchar()) != EOF){
		if(whitespace && (c == ' ' || c == '\t')){
			continue;
		} else if(!whitespace && (c == ' ' || c == '\t')){
			whitespace = true;
		} else {
			whitespace = false;
		}

		if(newline && c == '\n'){
			continue;
		} else if(!newline && c == '\n'){
			newline = true;
		}else {
			newline = false;
		}
		putchar(c);
	}
	return 0;
}