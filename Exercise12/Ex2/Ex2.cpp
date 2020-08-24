// Ex2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "stdio.h"

struct tree
{
	char key;
	struct tree *left;
	struct tree *right;
};

struct tree * SearchTree(char x, struct tree *v)
{
	if (v != NULL)
	{
		if (x < v->key)
			SearchTree(x, v->left);
		else
			if (x > v->key)
				SearchTree(x, v->right);
			else
				return v;
		printf("The element is found: %c!", v);
	}
	else
		printf("The element is not in the tree!");
		return NULL; 
}

void InsertNode(char x, struct tree ** v)
{ 
	if (*v != NULL)
	{
		if (x < (*v)->key)
			InsertNode(x, &(*v)->left);
		else   
			if (x > (*v)->key) 
				InsertNode(x, &(*v)->right);
	}
	else
	{ 
		(*v) = (struct tree *) malloc(sizeof(struct tree));
		(*v)->key = x;  
		(*v)->left = NULL;
		(*v)->right = NULL; 
	}
}

void DeleteNode(char x, struct tree ** v)
{
	if (*v == NULL)
		printf("\nThe element miss!");
	else
	{
		if (x < (*v)->key)
			DeleteNode(x, &(*v)->left);
		else
			if (x > (*v)->key)
				DeleteNode(x, &(*v)->right);
			else
			{
				if ((*v)->left != NULL && (*v)->right != NULL)
				{
					struct tree * h = (*v)->right;
					while (h->left != NULL)
						h = h->left;
					(*v)->key = h->key;
					DeleteNode((*v)->key, &(*v)->right);
				}
				else
				{
					struct tree * tmp = *v;
					if ((*v)->left)
						(*v) = (*v)->left;
					else
						(*v) = (*v)->right;
					free(tmp);
				}
			}
	}
}

void readtree(struct tree **v, char &x)
{
	char y, z;
	struct tree * q1, *q2;
	if (*v == NULL)
	{
		printf("Enter the root: ");
		scanf_s("%c", &x);
		(*v) = (struct tree *)malloc(sizeof(struct tree));
		(*v)->key = x;
	}
	fflush(stdin);
	printf("\nEnter left heir on %c: ", x);
	z = getchar();
	fflush(stdin);
	printf("\nEnter right heir on %c: ", x);
	y = getchar();
	if (z != '0')
	{
		q1 = (struct tree *)malloc(sizeof(struct tree));
		q1->key = z;
		(*v)->left = q1;
		readtree(&q1, z);
	}
	else
		(*v)->left = NULL;
	if (y != '0')
	{
		q2 = (struct tree *)malloc(sizeof(struct tree));
		q2->key = y;
		(*v)->right = q2;
		readtree(&q2, y);
	}
	else
		(*v)->right = NULL;
}

void printtree(struct tree * v, int delta)
{
	int i;
	if (v != NULL)
	{
		printtree(v->left, delta + 1);
		for (i = 1; i <= delta; i++)
			printf("\t");
		printf("%c", v->key);
		printf("\n");
		printtree(v->right, delta + 1);
	}
}

int main()
{
	struct tree *tree;
	tree = NULL;
	char key;
	char element_to_search, element_to_add, element_to_delete;

	readtree(&tree, key);
	printf("\n");
	printtree(tree, 0);
	printf("\n");

	printf("Enter element to search: ");
	scanf_s("%c", &element_to_search);
	SearchTree(element_to_search, tree);
	printf("Enter element to add: ");
	scanf_s("%c", &element_to_add);
	InsertNode(element_to_add, &tree);
	printf("Enter element to delete: ");
	scanf_s("%c", &element_to_delete);
	DeleteNode(element_to_delete, &tree);

	printf("The new tree is: ");
	printtree(tree, 0);
	printf("\n");
	return 0;
}
