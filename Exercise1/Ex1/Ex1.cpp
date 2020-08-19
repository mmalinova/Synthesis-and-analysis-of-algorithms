// Ex1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "math.h"

int funcOne(int n, int m)
{
	if (m == 0)
		return n;
	while (n != 0)
	{
		if (m > n)
			m = m - n;
		else
			n = n - m;
	}
	return m;
}

int funcTwo(int n, int m)
{
	int k;
	while (n != 0)
	{
		k = n;
		n = m % n;
		m = k;
	}
	return m;
}

int main()
{
	int a, b, c, d;
	printf("Enter a number for a: ");
	scanf_s("%d", &a);
	printf("Enter a number for b: ");
	scanf_s("%d", &b);
	c = funcOne(a, b);
	printf("NGOD: %d", c);
	d = funcTwo(a, b);
	printf("\nNGOD: %d\n", d);

    return 0;
}

