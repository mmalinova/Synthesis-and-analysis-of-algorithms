// Ex1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"

int main()
{
	int P[101], A[11];
	int i, j;
	printf("Enter a numbers:\n");
	for (i = 0; i < 11; i++)
	{
		printf("A[%d]: ", i);
		scanf_s("%d", &A[i]);
	}
	for (j = 0; j < 101; j++)
	{
		P[j] = 0;
	}
	for (i = 0; i < 11; i++)
	{
		P[A[i]]++;
	}
	for (i = 0; i < 101; i++)
	{
		if (P[i] != 0)
		{
			printf("\n%d - %d\n", i, P[i]);
		}
	}
    return 0;
}

