// SAA_KR.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "stdio.h"
#include "windows.h"

void pyramid(int n);

void pyramid(int n)
{
	int i, j;
	int row = 1;
	for (i = n; i >= 1; i--)
	{
		for (j = 1; j <= i * 2; j++)
		{
			if (row <= 10)
				printf(" ");
			if (row > 10)
				printf("  ");
		}
		for (j = i; j <= n; j++)
		{
			printf("%d ", j);
		}
		for (j = n; j >= i; j--)
		{
			printf("%d ", j);
		}
		printf("\n");
	}
	row++;
}
int main()
{
	int n, t1, t2;
	printf("Enter n: ");
	scanf_s("%d", &n);
	printf("\n");
	t1 = GetTickCount();
	pyramid(n);
	t2 = GetTickCount();
	printf("\n%d\n", (t2 - t1));
	return 0;
}