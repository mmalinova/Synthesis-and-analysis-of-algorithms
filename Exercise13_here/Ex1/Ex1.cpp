// Ex1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "stdio.h"
#define N 100
int used[N];

void dfs(int x, int n, int A[N][N])
{
	int i;
	used[x] = 1;
	printf("\t%d,", x);
	for (i = 0; i < n; i++)
		if (A[x][i] && !used[i]) dfs(i, n, A);
}

int main()
{
	int n, m, i, a, b, v = 0;
	int A[N][N];
	printf("\nEnter number of vertices: ");
	scanf_s("%d", &n);
	printf("Enter number of hips: ");
	scanf_s("%d", &m);
	printf("\t\nEnter the hips:\n");
	for (i = 0; i < m; i++)
	{
		scanf_s("%d %d", &a, &b);
		A[a][b] = A[b][a] = 1;
	}
	for (i = 0; i < n; i++)
		used[i] = 0;
	printf("Enter a start vertex: ");
	scanf_s("%d", &v);
	printf("Crawling in depth from a vertex %d: \n", v);
	dfs(v, n, A);
	printf("\n");
	return 0;

}

