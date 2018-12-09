/*
	Celsius to Fahrenheit and Fahrenheit to Celsius Convertor.
*/
#include<stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP  20

double fahr2Celsius(double);
double celsius2Fahr(double);
int main()
{
	float fahr, celsius;

	celsius = LOWER;
	printf("\nCelsius to Fahrenheit Convertor\n");
	printf("Celsius\tFahrenheit\n" );
	while(celsius <= UPPER)
	{
		printf("%3.2f\t%8.2f\n", celsius, celsius2Fahr(celsius));
		celsius = celsius + STEP;

	}
	printf("\nFahrenheit to Celsius Convertor\n");
	printf("\nFahrenheit\tCelsius\n" );
	fahr = LOWER;
	while(fahr <= UPPER)
	{
		printf("%8.2f\t%3.2f\n", fahr,fahr2Celsius(fahr));
		fahr = fahr + STEP;

	}
	return 0;
}

double fahr2Celsius(double fahr){
	double returnValue;
	returnValue = 5 * (fahr-32) / 9.0;
	return returnValue;
}
double celsius2Fahr(double celsius){
	double returnValue;
	returnValue = (9.0/5.0 * celsius) + 32;
	return returnValue;
}