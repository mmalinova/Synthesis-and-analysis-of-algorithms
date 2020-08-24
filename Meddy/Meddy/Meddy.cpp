// Meddy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "stdio.h"
#include "stdlib.h"

int main()
{
	int n, a, b, c, d, k;
	printf("Enter n: ");
	scanf_s("%d", &n);
	for (k = 0; k < n; )
	{
		a = rand() % 100;
		b = rand() % 100;
		c = rand() % 100;
		d = rand() % 100;
		if (a * a + b * b + c * c == d * d)
		{
			printf("\n%d^2 + %d^2 + %d^2 = %d^2\n", a, b, c, d);
			k++;
		}
	}
	return 0;
}