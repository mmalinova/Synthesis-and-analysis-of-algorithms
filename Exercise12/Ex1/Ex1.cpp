// Ex1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "stdio.h"

void quicksort(float A[], int start, int stop)
{
	int i = start, j = stop;
	float m, x;
	m = A[(start + stop) / 2];
	do {
		while (A[i] < m) i++;
		while (A[j] > m) j--;
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

int BinSearch(int l, int r, float x, float A[])
{
	int m;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (x < A[m])
			r = m - 1;
		else
			if (x > A[m])
				l = m + 1;
			else
				return m;
	}
	return -1;
}

int SecondSearch(int n, float B[], float x)
{
	int i = 0;
	B[n] = x;
	while (B[i] != x)
		i++;
	if (i < n)
		return i;
	return -1;
}

int FirstSearch(int n, float B[], float x)
{
	int i;
	for (i = 0; i < n; i++)
		if (B[i] == x)
			return i;
	return -1;
}

int main()
{
	int n, i, k;
	float x;
	printf("Enter number of elements: ");
	scanf_s("%d", &n);
	float *A = (float*)malloc(sizeof(float) * n);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("Enter element for A[%d]: ", i);
		scanf_s("%f", &A[i]);
	}
	printf("\nEnter search element: ");
	scanf_s("%f", &x);

	quicksort(A, 0, n - 1);
	printf("\nSorted array is: \n");
	printArray(A, n);
	k = BinSearch(0, n - 1, x, A);
	if (k == -1)
		printf("\nThe element is not in the array!\n\n");
	else
		printf("\nThe element is on %d position!\n\n", k);

	float *B = (float*)malloc(sizeof(float) * (n + 1));
	for (i = 0; i < n; i++)
	{
		printf("Enter element for B[%d]: ", i);
		scanf_s("%f", &B[i]);
	}
	printf("\nEnter search element: ");
	scanf_s("%f", &x);

	k = SecondSearch(n, B, x);
	if (k == -1)
		printf("\nThe element is not in the original array!\n");
	else
		printf("\nThe element is on %d position!\n", k);

	k = FirstSearch(n, B, x);
	if (k == -1)
		printf("\nThe element is not in the array!\n");
	else
		printf("\nThe element is on %d position!\n", k);
}

