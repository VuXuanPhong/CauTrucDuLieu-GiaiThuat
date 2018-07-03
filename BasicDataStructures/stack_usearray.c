/*************************SOLVE DATA STRUCTURES PROBLEM*******************************
When            Who         What
29/04/2018      Phong      Basic Data Structures stack use array

*************************************************************************************/

/*
** Description:
	Stack use array...
*/
#include <stdio.h>
#include <stdlib.h>

#define N 10000
#define inf -1000000
typedef int data;


struct _stack{
	data* st;
	int size;
	int top;
};

typedef struct _stack Stack;

//method
Stack* init();
void push(Stack* st, data d);
data pop(Stack* st);
data top(Stack* st);
int isEmpty(Stack* st);
int isFull(Stack* st);
int size(Stack* st);
void display(Stack* st);

int main(){
	Stack* st = NULL;
	st = init();
	push(st,5);
	push(st,4);
	push(st,2);
	display(st);
	printf("%d \n",pop(st));
	printf("%d \n",top(st));
	printf("%d \n",pop(st));
	printf("%d \n",pop(st));
	return 0;
}

Stack* init(){
	Stack* stack = NULL;
	stack = (Stack*) malloc(sizeof(Stack));
	if(stack == NULL) {
		printf("Not enough memory. \n");
		exit(0);
	}
	data* _st = NULL;
	_st = (data*) malloc(N*sizeof(data));
	if(_st == NULL) {
		printf("Not enough memory. \n");
		exit(0);	
	}
	stack->st = _st;
	stack->size = 0;
	stack->top = 0;
	return stack;
}

void push(Stack* st, data d){
	if(st->size >= N ) {
		printf("stack overflow.\n");
		return;
	}
	st->st[st->top] = d;
	st->top++;
	st->size++;
}

data pop(Stack* st){
	if(st->size == 0) return inf;
	data d = st->st[st->top-1];
	st->top--;
	return d;
}

data top(Stack* st){
	if(st->size == 0) return inf;
	return st->st[st->top-1];
}

int isEmpty(Stack* st){
	return (st->size == 0);
}

int isFull(Stack* st){
	return (st->size == N);
}

int size(Stack* st){
	return (st->size);
}

void display(Stack* st){
	int id = st->top-1;
	while(id>=0){
		printf("%d ",st->st[id]);
		id--;
	}
	printf("\n");
}
