// Ex1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"

void quicksort(float A[], int start, int stop) 
{    
	int i = start, j = stop;
	float m, x;
	m = A[(start + stop) / 2];
	do  {  
		while (A[i]<m) i++;
		while (A[j]>m) j--;
		if (i <= j) 
		{ 
			x = A[i];
			A[i] = A[j];
			A[j] = x;
			i++; 
			j--;
		}
	} while (i <= j);
	if (start < j)  
		quicksort(A, start, j); 
	if (i < stop)
		quicksort(A, i, stop);
}

void printArray(float A[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%.1f\n", A[i]);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n, i;
	float A[100];
	printf("Enter n: ");
	scanf_s("%d", &n);
	printf("\tEnter elements for the array:\n");
	for (i = 0; i < n; i++)
	{
		printf("A[%d]: ", i);
		scanf_s("%f", &A[i]);
	}
	quicksort(A, 0, n - 1);
	printf("\tSorted array is: \n");
	printArray(A, n);
	printf("\n");
	return 0;
}

