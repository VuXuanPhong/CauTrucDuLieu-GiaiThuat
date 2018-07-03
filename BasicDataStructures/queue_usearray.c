/*************************SOLVE DATA STRUCTURES PROBLEM******************************
When            Who         What
29/04/2018      Phong      Basic Data Structures queue use array

*************************************************************************************/

/*
** Description:
	Queue use array.
*/
#include <stdio.h>
#include <stdlib.h>

#define N 1000000
#define inf -1000000

typedef int data;

struct _queue{
	int front, rear;
	data* queue;
};

typedef struct _queue Queue;

Queue* initQueue(){
	Queue* q = NULL;
	q = (Queue*) malloc(sizeof(Queue));
	if(q == NULL) {
		printf("Not enough memory. \n");
		exit(0);
	}
	q->front = 0;
	q->rear = 0;
	data* d = NULL;
	d = (data*) malloc(N*sizeof(data));
	if(d==NULL){
		printf("Not enough memory. \n");
		exit(0);
	}
	q->queue = d;
	return q;
}

int size(Queue* q){
	return (N- q->front + q->rear)%N;
}

void enqueue(Queue* q, data d){
	if(q==NULL || q->queue == NULL) return;
	if(size(q) == N-1) return;
	q->queue[q->rear] = d;
	q->rear = (q->rear + 1)%N;
}

data dequeue(Queue* q){
	if(q->front == q->rear) return inf;
	data d = q->queue[q->front];
	q->front = (q->front+1)%N;
	return d;
}


int main(){
	Queue* q = initQueue();
	enqueue(q,1);
	enqueue(q,3);
	enqueue(q,5);
	enqueue(q,4);
	printf("%d \n", dequeue(q));
	printf("%d \n", dequeue(q));
	printf("%d \n", dequeue(q));
	printf("%d \n", dequeue(q));
	printf("%d \n", dequeue(q));
	return 0;
}
