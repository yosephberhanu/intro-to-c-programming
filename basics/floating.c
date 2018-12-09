#include<stdio.h>

int main(){
	float num = 104054.7654321;
	int number = 59044;
	printf("f %f\n", num);
	printf("3f %3f\n", num);
	printf("5f %5f\n", num);
	printf("5.1f %5.1f\n", num);
	printf("4.1f %4.1f\n", num);
	printf("5.5f %5.5f\n", num);
	printf("5.8f %5.8f\n", num);
	printf("octal %o\n",number );
	printf("decimal %d\n",number );
	printf("hexadecimal %x\n",number );
}