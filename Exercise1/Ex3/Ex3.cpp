// Ex3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "math.h"

int funcOne(int n, int m)
{
	int k;
	if (n == 0)
		return m;
	k = funcOne(m % n, n);
	return k;
}

int main()
{
	int a, b, c;
	printf("Enter a number for a: ");
	scanf_s("%d", &a);
	printf("Enter a number for b: ");
	scanf_s("%d", &b);
	c = funcOne(a, b);
	printf("NGOD: %d\n", c);
    return 0;
}

