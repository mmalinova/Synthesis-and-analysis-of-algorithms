// Ex2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "math.h"

int funcOne(int n, int m)
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
	int a, b, c, d, e;
	printf("Enter a number for a: ");
	scanf_s("%d", &a);
	printf("Enter a number for b: ");
	scanf_s("%d", &b);
	c = funcOne(a, b);
	printf("NGOD: %d", c);
	d = a / c;
	e = b / c;
	printf("\n%d / %d\n", d, e);

    return 0;
}

