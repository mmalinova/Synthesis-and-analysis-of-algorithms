// Exercise3.cpp : Defines the entry point for the console application.


#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct bracket 
{
	char symbol;  
	struct bracket * prev; 
} *sp = NULL;

int Push(char c)
{
	struct bracket *ptr;
	ptr = (struct bracket *)malloc(sizeof(struct bracket));
	if (!ptr)    
		return 0;
	ptr->symbol = c;  
	ptr->prev = sp; 
	sp = ptr;  
	return 1;
}

int checkStack(char c)
{
	char mirror; 
	struct bracket * ptr;  
	switch (c)  
	{
	    case ')':    
			mirror = '(';    
			break;   
		case '}':    
			mirror = '{';   
			break;   
		case ']':    
			mirror = '[';    
			break; }  
	if (sp && sp->symbol == mirror)  
	{ 
		ptr = sp;   
		sp = sp->prev;
		free(ptr);   
		return 1; 
	}
	else    
		return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char a[50];
	int b;
	printf("Enter a expression: ");
	gets_s(a);
	for (int i = 0; i < strlen(a); i++)
	{

		if (a[i] == '(' || a[i] == '[' || a[i] == '{')
			Push(a[i]);
		else if (a[i] == ')' || a[i] == ']' || a[i] == '}')
		{
			b = checkStack(a[i]);
			if (b == 0)
			{
				printf("The expression is false!\n");
				return 0;
			}
		}
	}
	if (sp == NULL)
	{
		printf("The expression is true!\n");
	}
	else
	{
		printf("The expression is false!\n");
	}
	return 0;
}

