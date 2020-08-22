// Ex1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct queue {
	int rank; 
	char task[20];
    struct queue * next;
} *head = NULL;

struct queue *findPlace(int rank)
{
	struct queue *f, *s;
	f = head;
	s = NULL;
	while (f != NULL && f ->rank <= rank)
	{
		s = f;
		f = f->next;
	}
	return s;
}

int addElement(int rank, char *task)
{
	struct queue *ptr, *ptr1;
	ptr = (struct queue *)malloc(sizeof(struct queue));
	if (!ptr)
		return 0;
	ptr->rank = rank;
	strcpy_s(ptr->task, task);
	ptr1 = findPlace(rank);
	if (!ptr1)
	{
		ptr->next = head;
		head = ptr;
	}
	else 
	{
		ptr->next = ptr1->next;
		ptr1->next = ptr;
	}  
	return 1;
}

int deleteElement(int rank)
{
	struct queue *temp;
	temp = (struct queue*)malloc(sizeof(struct queue));
	if (!temp)
		return 0;
	rank = head->rank;
	temp = head; 
	head = head->next;
	free(temp);
	return 0;
}

void printTaskQueue() 
{ 
	struct queue * ptr = head;
	while (ptr)
	{ 
		printf("%s, %d\n", ptr->task, ptr->rank);
		ptr = ptr->next;
	} 
}

int main()
{
	struct queue *data;
	int i, numbers;
	printf("Enter number of tasks: ");
	scanf_s("%d", &numbers);
	data = (struct queue*)malloc(sizeof(struct queue) * numbers);
	for (i = 0; i < numbers; i++)
	{
		printf("Enter task: ");
		gets_s(data->task);
		printf("Enter rank: ");
		scanf_s("%d", &data->rank);
	} 
	addElement(data->rank, data->task);
	printTaskQueue();
	return 0;
}