#include<stdio.h>

int main(){

	int c;
	while((c=getchar())!=EOF){
		putchar(c);
	}
	printf("\nValue of EOF:%d\n",c);
	return 0;
}