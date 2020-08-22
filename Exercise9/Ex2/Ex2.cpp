// Ex2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"

void sort(int A[], int n)
{
	int i, j, k, total = 0;
	int min = 0;
	int max = 15;
	for (i = 0; i < n; i++)
	{
		total = total + A[i];
	}
	int *P = (int*)malloc(sizeof(int)* (total + 1));
	for (i = min; i <= max; i++)
		P[i] = 0;
	for (j = 0; j < n; j++)
		P[A[j]]++;
	j = 0;
	for (i = min; i <= max; i++)
	{
		for (k = 0; k < P[i]; k++) 
			A[j++] = i;
	}
	free(P);
}

void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%d\n", A[i]);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n, i;
	int A[100];
	printf("Enter n: ");
	scanf_s("%d", &n);
	printf("\tEnter elements for the array [0 - 15]:\n");
	for (i = 0; i < n; i++)
	{
		printf("A[%d]: ", i);
		scanf_s("%d", &A[i]);
	}
	sort(A, n);
	printf("\tSorted array is: \n");
	printArray(A, n);
	printf("\n");
	return 0;
}

