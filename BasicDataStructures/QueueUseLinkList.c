#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef int Item;

struct QueueNode
{
	Item data;
	QueueNode* next;
};

struct Queue {
	QueueNode* first;
};

Queue* queue = NULL;

Queue* QueueInit(){
	Queue* q;
	q= (Queue*)malloc(sizeof(Queue));
	if (q == NULL){
		printf("Can't create queue \n");
		return NULL;
	}
	q->first = NULL;
	return q;
}

int QueueEmpty(Queue* q){
	return (q->first == NULL);
}

void EnQueue(Item x, Queue* q){
	if (q == NULL){
		printf("Chua khoi tao hang doi \n");
		return;
	}

	QueueNode* newNode = NULL;
	newNode = (QueueNode*)malloc(sizeof(QueueNode));
	
	if (newNode == NULL){
		printf("Khong du bo nho \n");
		return;
	}
	newNode->data = x;
	newNode->next = NULL;

	if (q->first == NULL) {
		q->first = newNode;
		q->first->next = NULL;
	}
	else{
		QueueNode* temp = q->first;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

Item DeQueue(Queue* q){
	if (q->first == NULL){
		printf("Hang doi rong \n");
		return NULL;
	}
	QueueNode* temp = q->first->next;
	QueueNode* temp1 = q->first;
	q->first = temp;
	return (temp1->data);
}

int main(){
	queue = QueueInit();
	EnQueue(5, queue);
	EnQueue(7, queue);
	EnQueue(9, queue);
	EnQueue(11, queue);
	while (!QueueEmpty(queue))
	{
		printf("%d \n", DeQueue(queue));
	}
	_getch();
	return 0;
}