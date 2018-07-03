/*************************SOLVE DATA STRUCTURES PROBLEM******************************
When            Who         What
29/04/2018      Phong      Basic Data Structures queue use link list

*************************************************************************************/

/*
** Description:
	Queue use link list.
*/
#include <stdio.h>
#include <stdlib.h>

typedef int data;

struct _node{
	data d;
	struct _node* pNext;
};

typedef struct _node Node;

struct _queue{
	Node* front;
	Node* rear;
	int size;
};

typedef struct _queue Queue;

Queue* initQueue(){
	Queue* q = NULL;
	q = (Queue*) malloc(sizeof(Queue));
	if(!q) {
		printf("Not enough memory. \n");
		exit(0);
	}
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
	return q;
}

Node* makeNewNode(data d){
	Node* temp = NULL;
	temp = (Node*) malloc(sizeof(Node));
	if(!temp){
		printf("Not enough memory. \n");
		exit(0);
	}
	temp->d =  d;
	temp->pNext = NULL;
	return temp;
}

void enqueue(Queue* q, data d){
	if(q==NULL) return;
	Node* node = makeNewNode(d);
	if(q->front == NULL && q->rear == NULL){
		q->front = node;
		q->rear = node;
	}
	else{
		q->rear->pNext = node;
		q->rear = node;
	}
	q->size ++;
}

Node* dequeue(Queue* q){
	if(q == NULL || q->size == 0) return NULL;
	Node* t = q->front;
	q->front = t->pNext;
	t->pNext = NULL;
	if(q->front == NULL) q->rear = NULL;
	q->size--;
	return t;
}

int isEmpty(Queue* q){
	return (q->size == 0);
}

void removeQueue(Queue* q){
	Node* d = dequeue(q);
	while(d!= NULL){
		free(d);
		d = dequeue(q);
	}
}


int main(){
	Queue* q = initQueue();
	enqueue(q,4);
	enqueue(q,5);
	enqueue(q,1);
	enqueue(q,2);
	Node* d = dequeue(q);
	while(d!= NULL){
		printf("%d \n",d->d);
		free(d);
		d = dequeue(q);
	}
	removeQueue(q);
	printf("%d \n",q->size); 
	return 0;
}
