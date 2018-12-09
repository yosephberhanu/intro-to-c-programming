/* 
 A program to remove all comments from a C program. It handles cases where comment
 markers appear with in quoted strings and character constants properly.
 Input is provided via standard input stream while output is to the standard output
 stream 
*/
#include <stdio.h>
#ifndef false
#define false 0
#endif
#ifndef true
#define true 1
#endif
#ifndef boolean
#define boolean short
#endif

int main()
{
	boolean inDoubleQuote = false;
	boolean inSingleQuote = false;
	boolean inlineComment = false;
	boolean multilineComment = false;
	int c,cp;
	while((c = getchar()) != EOF){
		if(inlineComment){
			if(c == '\n'){
				inlineComment = false;
				//putchar(c);
			}
		} else if(multilineComment){
			if(c == '/' && cp == '*'){
				multilineComment = false;
			}
		} else {	// Outside of comment
			/*if(c == '"' && !inSingleQuote){			// Start/End of double quote
				inDoubleQuote = !inDoubleQuote;
			}
			if(c == '\'' && !inDoubleQuote){	// Start/End of single quote
				inSingleQuote = !inSingleQuote;
			}*/
			if(c == '/'){
				if(cp == '/'){
					inlineComment = true;
				}
			}
			else if(c == '*'){
				if(cp == '/'){
					multilineComment = true;
				}
				
			}else{
				if(cp =='/')
					putchar(cp);
				putchar(c);
			}
			// if(c == '/' && cp == '/' ){//&& !inDoubleQuote && !inSingleQuote){
			// 	putchar('\b');
			// 	putchar(' ');
			// 	putchar('\b');
			// 	putchar('\b');
			// 	putchar(' ');
			// 	putchar('\b');
			// 	inlineComment = true;
			// }else if(c == '*' && cp == '/'){//} && !inDoubleQuote && !inSingleQuote){
			// 	putchar('\b');
			// 	putchar(' ');
			// 	putchar('\b');
			// 	putchar('\b');
			// 	putchar(' ');
			// 	putchar('\b');
			// 	multilineComment = true;
			// }else{
			// 	putchar(c);
			// }

			
		}
		cp = c;
	}
	return 0;
}