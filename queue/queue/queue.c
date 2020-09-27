#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int data;
	struct Node* next;
}Node;
typedef struct {
	Node* rear;
	Node* front;
	int count;
}queue;

push(queue* q, int data)
{
	Node* node = malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	if (q->count == 0)
		q->front = node;
	else q->rear->next = node;
	q->rear = node;
	q->count++;
}
int pop(queue* q)
{
	Node* node = q->front;
	int res = node->data;
	q->front = node->next;
	free(node);
	q->count--;
	return res;
}
showAll(queue* q)
{
	Node* cur = q->front;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}
freeAll(queue* q)
{
	Node* FA = q->front;
	while (FA != NULL)
	{
		free(FA);
		FA = FA->next;
	}
}
main()
{
	queue q;
	q.count = 0;
	q.rear = q.front = NULL;
	push(&q, 1);
	push(&q, 2);
	push(&q, 3);
	push(&q, 4);
	push(&q, 5);
	push(&q, 6);
	pop(&q);
	showAll(&q);
	freeAll(&q);
}