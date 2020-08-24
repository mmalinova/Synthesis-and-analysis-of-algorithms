// S.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "stdio.h"
#include "stdlib.h"

struct tree
{
	int key;
	struct tree *left;
	struct tree *right;
};

void inOrder(struct tree *v, int t1, int t2)
{
	if (v != NULL)
	{
		inOrder(v->left, t1, t2);
		if (v->key >= t1 && v->key <= t2)
			printf("%d\n", v->key);
		inOrder(v->right, t1, t2);
	}
}

void readtree(struct tree ** p, int &x)
{
	int y, z;
	struct tree * q1, *q2;
	if (*p == NULL)
	{
		printf("Vyvedi korena: ");
		scanf_s("%d", &x);
		(*p) = (struct tree *)malloc(sizeof(struct tree));
		(*p)->key = x;
	}
	fflush(stdin);
	printf("\nVyvedi liav naslednik na %d: ", x);
	scanf_s("%d", &z);
	fflush(stdin);
	printf("\nVyvedi desen naslednik na %d: ", x);
	scanf_s("%d", &y); 
	if (z != 0)
	{
		q1 = (struct tree *)malloc(sizeof(struct tree));
		q1->key = z;
		(*p)->left = q1;
		readtree(&q1, z);
	}
	else
		(*p)->left = NULL;
	if (y != 0)
	{
		q2 = (struct tree *)malloc(sizeof(struct tree));
		q2->key = y;
		(*p)->right = q2;
		readtree(&q2, y);
	}
	else
		(*p)->right = NULL;
}

void printtree(struct tree * p, int delta)
{
	int i;
	if (p != NULL)
	{
		printtree(p->left, delta + 1);
		for (i = 1; i <= delta; i++)
			printf("\t");
		printf("%d", p->key);
		printf("\n");
		printtree(p->right, delta + 1);
	}
}

int main()
{
	struct tree *n;
	n = NULL;
	int key, t1, t2;

	readtree(&n, key);
	printf("\n");
	printtree(n, 0);
	printf("\n");
	printf("Enter t1: ");
	scanf_s("%d", &t1);
	printf("Enter t1: ");
	scanf_s("%d", &t2);
	printf("\nVyrhovete v intervala [%d - %d] sa:\n", t1, t2);
	inOrder(n, t1, t2);
    return 0; 
}

