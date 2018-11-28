

/*
Author Mustafa El Behidy
Thursday 1/11/2018
Solving_Engineering_Problems_Part_1
*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#define EPSLON 0.0000001

#define MAX_NAME_SIZE 50
void Sort_INT(int* Values, int n);
void Sort_String(char Values[][MAX_NAME_SIZE], int n);
void Print(int* Values, int n);
double EvaluatePolynomial(double Ceofficient[], int n, double x);
double Finite_Series(double coeffficient, double x, int n);
int Factorial(int n);
double Power(double base, double exponent);
double InFinite_Series();

int main()
{
	printf("%.2lf\r\n", InFinite_Series());
}
double InFinite_Series()
{
	double Sum = 0, term = 0;
	int m = 1;
	do
	{
		term = 1.0 / (m * m);
		Sum += term;
		m++;
	} while (fabs(term) > EPSLON);
	printf("m : %d\r\n", m);
	return Sum;
}
double Finite_Series(double coeffficient, double x, int n)
{
	double Sum = 0, xterm = 1, term = 0, fterm = 1;
	int i;
	for (i = 0; i <= n; i++)
	{
		// if condition instead of Factorial Function
		// Optimization Technique
		if (i > 0)
			fterm *= i;
		term = (x * xterm) / fterm;
		Sum += term;
		// xterm is Optimization technique instaed of using pow() Function
		xterm *= x;

	}
	return Sum;
}
double Power(double base, double exponent)
{
	if (exponent != 0)
	{
		return base * Power(base, exponent - 1);
	}
	else
		return 1;
}
int Factorial(int n)
{
	if (n != 0)
	{
		return n * Factorial(n - 1);
	}
	else
		return 1;
}

double EvaluatePolynomial(double Ceofficient[], int n, double x)
{
	int i;
	double Sum = 0, xterm = 1;
	for (i = 0; i < n; i++)
	{
		Sum += Ceofficient[i] * xterm;
		xterm *= x;
	}
	return Sum;
}


void Sort_String(char Values[][MAX_NAME_SIZE], int n)
{
	int i, j;
	char temp[50];
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (stricmp(Values[i], Values[j]) > 0)
			{
				strcpy(temp, Values[i]);
				strcpy(Values[i], Values[j]);
				strcpy(Values[j], temp);
			}
		}
	}
}
void Print(int* Values, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d\r\n", Values[i]);
	}
}
void Sort_INT(int* Values, int n)
{
	//Ascending Sort
	int i, j, temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i+1; j < n; j++)
		{
			if (Values[i] > Values[j])
			{
				temp = Values[i];
				Values[i] = Values[j];
				Values[j] = temp;
			}
		}
	}
}