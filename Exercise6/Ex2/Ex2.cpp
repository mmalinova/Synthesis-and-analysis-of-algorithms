// Ex2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"

int fibonaccii(int n) 
{
	if (n <= 1)
		return 1;
	return fibonaccii(n - 1) + fibonaccii(n - 2);
}

int fibonaccii_l(int n) 
{ 
	int i, f1 = 1, f2 = 1, f;
	for (i = 2; i <= n; i++)
	{ 
		f = f1 + f2; 
		f2 = f1; f1 = f;
	}   
	return f;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n, t1, t2, t3;
	printf("Enter number of numbers: ");
	scanf_s("%d", &n);
	t1 = GetTickCount();
	fibonaccii(n);
	t2 = GetTickCount();
	fibonaccii_l(n);
	t3 = GetTickCount();
	printf("The time is: %d\n", (t3 - t2));
	printf("The time is: %d\n", (t2 - t1));

	return 0;
}

