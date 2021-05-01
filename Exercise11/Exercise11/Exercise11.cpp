// Exercise11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"

struct  node
{ 
	char key; 
	struct node * left; 
	struct node * right;
};

int calc(struct node *v)
{
	if (v != NULL)
	{
		if (v->key >= '0' && v->key <= '9')
			return (v->key - '0');
		switch (v->key)
		{
		case '+':
			return calc(v->left) + calc(v->right);
			break;
		case '-':
			return calc(v->left) - calc(v->right);
			break;
		case '*':
			return calc(v->left) * calc(v->right);
			break;
		}
	}
}

void inOrder(struct node *v)
{
	if (v != NULL)
	{
		inOrder(v->left);
		printf("%c\t", v->key);
		inOrder(v->right);
	}
}

void readtree(struct node ** p, char &x) 
{
	char y, z; 
	struct node * q1, *q2;
	// създава корена, ако няма такъв до момента 
	if( *p == NULL ) 
	{  
		printf("Vyvedi korena: ");
		scanf_s( "%c", &x ); 
		(*p)=(struct node *)malloc(sizeof(struct node));
		(*p)->key=x; 
	} 
	fflush(stdin); 
	// въвежда ляв наследник на текущия връх
	printf("\nVyvedi liav naslednik na %c: ", x);
	z = getchar(); 
	fflush(stdin); 
	// въвежда десен наследник на текущия връх 
	printf("\nVyvedi desen naslednik na %c: ", x);
	y = getchar();

	// създава ляв наследник на текущия връх, ако стойността, въведена за него е  
	// различна от ‘0’  
	if (z != '0')
	{ 
		q1 = (struct node *)malloc(sizeof(struct node)); 
		q1->key = z;  
		(*p)->left = q1;
		readtree(&q1, z); 
	}
	else  
		(*p)->left = NULL;
	// създава десен наследник на текущия връх, ако стойността, въведена за него е  
	// различна от ‘0’ 
	if (y != '0')
	{
		q2 = (struct node *)malloc(sizeof(struct node));
		q2->key = y;  
		(*p)->right = q2;  
		readtree(&q2, y);
	}
	else   
		(*p)->right = NULL;
}

void printtree(struct node * p, int delta)
{ 
	int i; 
	if (p != NULL)  
	{ 
		printtree(p->left, delta + 1);
		for (i = 1; i <= delta; i++)  
			printf("\t"); 
		printf("%c", p->key);  
		printf("\n");   
		printtree(p->right, delta + 1);
	} 
}

int _tmain(int argc, _TCHAR* argv[])
{
	struct node * n;
	n = NULL;
	char key;
	int sum = 0;

	readtree(&n, key);
	printf("\n");
	printtree(n, 0);
	printf("\n");
	inOrder(n);
	sum = calc(n);
	printf("= \t%d\n", sum);
	return 0;
}

