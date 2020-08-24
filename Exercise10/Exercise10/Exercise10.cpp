// Exercise10.cpp : Defines the entry point for the console application.
//

#include"stdafx.h"
#include"stdio.h"
#include"stdlib.h"
#include"windows.h"
#define N 20000

void selection_sort(int A[], int n) 
{ 
	int i, j, x, min;
	for (i = 0; i < n - 1; i++) 
	{
		min = i;
		for (j = i + 1; j <= n - 1; j++) 
		if (A[j] < A[min]) min = j;
		if (min != i) 
		{
			x = A[min];
			A[min] = A[i];
			A[i] = x; 
		}
	} 
}

void insertion_sort(int A[], int n) 
{
	int i, j, x; 
	for (i = 1; i < n; i++)  
	{ 
		x = A[i];
		j = i - 1;
		while (j >= 0 && x < A[j]) 
		{ 
			A[j + 1] = A[j];
			j--; 
		}  
		A[j + 1] = x;
	}
}

void bubble_sort(int A[], int n)
{ 
	int i, j, x; 
	for (i = 0; i < n - 1; i++) 
	for (j = n - 1; j > i; j--)   
	if (A[j] < A[j - 1])     
	{
		x = A[j]; 
		A[j] = A[j - 1];  
		A[j - 1] = x;
	} 
}

void bubble_sort_flag(int A[], int n) 
{
	int i, x, flag;
	do  {
		flag = 1;  
		for (i = 0; i<n - 1; i++)  
		if (A[i]>A[i + 1])  
		{
			x = A[i];
			A[i] = A[i + 1]; 
			A[i + 1] = x;
			flag = 0;
		}
	} while (!flag);
}

void merge(int l, int m, int r, int A[])
{
	int i1 = l, i2 = m, j1 = m + 1, j2 = r, k = l, n = r - l + 1;
	int T[N];

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

void merge_sort(int l, int r, int A[])
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

void quicksort(int A[], int start, int stop)
{
	int i = start, j = stop;
	int m, x;
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

void digitalsort(int A[], int n)
{
	int i, j, k;
	int min = 0;
	int max = 9999;
	int P[10000];
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
}

int _tmain(int argc, _TCHAR* argv[])
{
	int i, t1, t2;
	int A[N];

	for (i = 0; i < N; i++)
		A[i] = rand() % 10000;
	t1 = GetTickCount();
	selection_sort(A, N);
	t2 = GetTickCount();
	printf("%d\n", (t2 - t1));

	for (i = 0; i < N; i++)
		A[i] = rand() % 10000;
	t1 = GetTickCount();
	insertion_sort(A, N);
	t2 = GetTickCount();
	printf("%d\n", (t2 - t1));

	for (i = 0; i < N; i++)
		A[i] = rand() % 10000;
	t1 = GetTickCount();
	bubble_sort(A, N);
	t2 = GetTickCount();
	printf("%d\n", (t2 - t1));

	for (i = 0; i < N; i++)
		A[i] = rand() % 10000;
	t1 = GetTickCount();
	bubble_sort_flag(A, N);
	t2 = GetTickCount();
	printf("%d\n", (t2 - t1));

	for (i = 0; i < N; i++)
		A[i] = rand() % 10000;
	t1 = GetTickCount();
	merge_sort(0, N - 1, A);
	t2 = GetTickCount();
	printf("%d\n", (t2 - t1));

	for (i = 0; i < N; i++)
		A[i] = rand() % 10000;
	t1 = GetTickCount();
	quicksort(A, 0, N - 1);
	t2 = GetTickCount();
	printf("%d\n", (t2 - t1));

	for (i = 0; i < N; i++)
		A[i] = rand() % 10000;
	t1 = GetTickCount();
	digitalsort(A, N);
	t2 = GetTickCount();
	printf("%d\n", (t2 - t1));

	return 0;
}

