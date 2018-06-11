/*************************SOLVE TREE PROBLEM****************************************
When            Who         What
29/04/2018      Phong      Basic Data Structures priority_queue

*************************************************************************************/
/*
** Mo ta:
	Priority Queue use single link list. Elements is inserted to head, and dequeue by tail.
	In this file C, all element is sorted by increasing
	
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct queueNode{
	int item;
	struct queueNode* next;
};

typedef struct queueNode QueueNode;

struct _PriorityQueue{
	QueueNode* front;
	QueueNode* rear;
	int size;
};

typedef struct _PriorityQueue PriorityQueue;

QueueNode* makeAQueueNode(int element);

PriorityQueue* init();

void enqueue(PriorityQueue* queue, int element);

QueueNode* dequeue(PriorityQueue* queue);
int isEmpty(PriorityQueue* queue);

int size(PriorityQueue* queue);
int freeQueue(PriorityQueue* queue);

int main(){
	PriorityQueue* pq = init();
	enqueue(pq,5);
	enqueue(pq,3);
	enqueue(pq,8);
	enqueue(pq,6);
	enqueue(pq,1);
	enqueue(pq,0);
	enqueue(pq,-5);
	enqueue(pq,5);
	enqueue(pq,3);
	enqueue(pq,8);
	enqueue(pq,6);
	enqueue(pq,1);
	enqueue(pq,0);
	enqueue(pq,-5);
	QueueNode* temp = NULL;
	printf("Cac phan tu cua hang doi co thu tu la: \n");
	while((temp = dequeue(pq))!= NULL){
		printf("\t%d \n",temp->item);
	}
	freeQueue(pq);
	getch();
	return 0;
}
QueueNode* makeAQueueNode(int element){
	QueueNode* q = NULL;
	q = (QueueNode*) malloc(sizeof(QueueNode));
	if(q == NULL){
		printf("Bo nho khong du \n");
		exit(1);
	}
	q->item = element;
	q->next = NULL;
	return q;
}

PriorityQueue* init(){
	PriorityQueue* pq = NULL;
	pq = (PriorityQueue*) malloc(sizeof(PriorityQueue));
	if(pq == NULL){
		printf("Bo nho khong du \n");
		exit(1);
	}
	pq->front = NULL;
	pq->rear = NULL;
	pq->size = 0;
}

void enqueue(PriorityQueue* queue, int element){
	QueueNode* q = makeAQueueNode(element);
	if(queue->front == NULL){
		queue->front = q;
		queue->rear = q;
	}
	else{
		if(element > queue->front->item){
			q->next = queue->front;
			queue->front = q;
		}
		else{
			 QueueNode* temp1 = queue->front;
			 QueueNode* temp2 = temp1->next;
			 while(temp2!=NULL){
			 	if(element <= temp2->item){
			 		temp1 = temp2;
			 		temp2 = temp1->next;
				 }
				 else break;
			 }
			 if(temp2 == NULL){
			 	temp1->next = q;
			 	q->next = NULL;
			 	queue->rear = q;
			 }
			 else{
			 	temp1->next = q;
			 	q->next = temp2;
			 }
		}
	}
	queue->size += 1;
}

QueueNode* dequeue(PriorityQueue* queue){
	if(queue->size == 0) return NULL;
	if(queue->size == 1){
		QueueNode* temp1 = queue->front;
		queue->front = NULL;
		queue->rear = NULL;
		queue->size = 0;
		return temp1;
	}
	QueueNode* temp =  queue->front;
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	queue->rear = temp;
	QueueNode* temp2 = temp->next;
	temp->next = NULL;
	queue->size -= 1;
	return temp2;
}
int isEmpty(PriorityQueue* queue){
	return (queue->size == 0);
}
int size(PriorityQueue* queue){
	return queue->size;
}
int freeQueue(PriorityQueue* queue){
	QueueNode* temp = NULL;
	while((temp=dequeue(queue))!= NULL){
		free(temp);
		temp = NULL;
	}
	return 1;
}
