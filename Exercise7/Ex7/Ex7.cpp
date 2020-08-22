// Ex7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int n, i, j;
	int total = 0;
	printf("Enter n: ");
	scanf_s("%d", &n);
	int *gifts = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		printf("Enter element for gifts[%d]: ", i);
		scanf_s("%d", &gifts[i]);
	}
	for (i = 0; i < n; i++)
	{
		total += gifts[i];
	}
	int *can = (int*)malloc(sizeof(int) * (total + 1));
	for (j = 0; j <= total; j++)
	{
		can[j] = 0;
	}
	can[0] = 1;
	for (i = 0; i < n; i++)
	{
		for (j = total; j >= 0; j--)
		{
			if (can[j] == 1)
				can[j + gifts[i]] = 1;
		}
	}
	j = total / 2;
	while (j > 0 && !can[j])
		j--;
	printf("Gifts for 1: %d\tGifts for 2: %d\n", j, total - j);
	free(gifts);
	free(can);
	return 0;
}

