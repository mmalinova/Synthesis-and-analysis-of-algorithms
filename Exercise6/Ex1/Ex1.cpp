// Ex1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#define N 100

void merge(int l, int m, int r, float A[])
{
	int i1 = l, i2 = m, j1 = m + 1, j2 = r, k = l, n = r - l + 1;
	float T[N];

	while ((i1 <= i2) && (j1 <= j2))
	{
		if (A[i1]<A[j1])
		{
			T[k] = A[i1];
			i1++;
		}
		else
		{
			T[k] = A[j1];
			j1++;
		}
		k++;
	}  while (i1 <= i2)
	{
		T[k] = A[i1];
		i1++;
		k++;
	}
	while (j1 <= j2)
	{
		T[k] = A[j1];
		j1++;
		k++;
	}
	for (k = 0; k<n; k++)
	{
		j1--;
		A[j1] = T[j1];
	}
}

void merge_sort(int l, int r, float A[]) 
{ 
	int m;
	if (l < r)  
	{ 
		m = (l + r) / 2; 
		merge_sort(l, m, A);
		merge_sort(m + 1, r, A);
		merge(l, m, r, A); 
	}
}

void printArray(float A[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%.1f", A[i]);
		printf("\n");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	float A[N];
	printf("Enter numbers of number: ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("Enter a number for A[%d]: ", i);
		scanf_s("%f", &A[i]);
	}
	printf("\nThe array is:\n");
	printArray(A, n);
	
	merge_sort(0, n - 1, A);
	printf("\nSorted array is: \n");
	printArray(A, n);
	return 0;
}

