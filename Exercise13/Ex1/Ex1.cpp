// Ex1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"stdio.h"
#define N 100

int A[N][N] =
{
	{0, 0, 0, 1, 1, 1},
	{0, 0, 0, 1, 1, 0},
	{0, 0, 0, 1, 1, 0},
	{1, 1, 1, 0, 0, 0},
	{1, 1, 1, 0, 0, 1},
	{1, 0, 0, 0, 1, 0},
};
int visited[N];
int n;

void dfs(int x)
{
	int i;
	visited[x] = 1;
	printf("\t%d,", x + 1);
	for (i = 0; i < n; i++)
		if (A[x][i] == 1 && !visited[i])
			dfs(i);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int v;
	printf("Enter number of vertex: ");
	scanf_s("%d", &n);
	printf("Enter start vertex: ");
	scanf_s("%d", &v);
	dfs(v - 1);
	printf("\n");
	return 0;
}

