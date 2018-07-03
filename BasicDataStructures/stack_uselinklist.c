/*************************SOLVE DATA STRUCTURES PROBLEM*******************************
When            Who         What
29/04/2018      Phong      Basic Data Structures stack use link list

*************************************************************************************/

/*
** Description:
	Stack use single link list...
*/
#include <stdio.h>
#include <stdlib.h>

#define inf -1000000
typedef int data;

struct _node{
	data d;
	struct _node* pNext;
};

typedef struct _node Node;

struct _stack{
	Node* top;
	int size;
};

typedef struct _stack Stack;

// method:

Node* makeNewNode(data d){
	Node* t = NULL;
	t = (Node*) malloc(sizeof(Node));
	if(t==NULL){
		printf("Not enough memori.\n");
		exit(0);
	}
	t->d = d;
	t->pNext = NULL;
	return t;
}

Stack* StackConstruct(){
	Stack* st = NULL;
	st = (Stack*) malloc(sizeof(Stack));
	if(st == NULL){
		printf("Not enough memory.\n");
		exit(0);
	}
	st->top = NULL;
	st->size = 0;
	return st;
}

void push(Stack* st, data d){
	if(st == NULL) {
		printf("Stack is NULL");
		return;
	}
	Node* t = makeNewNode(d);
	t->pNext = st->top;
	st->top = t;
	st->size++;
}

data pop(Stack* st){
	if(st == NULL || st->top == NULL) return inf;
	Node* t = st->top;
	st->top = t->pNext;
	t->pNext = NULL;
	data d = t->d;
	free(t);
	st->size--;
	return d; 
}

data top(Stack* st){
	if(st == NULL || st->top == NULL) return inf;
	return st->top->d;
}

int isEmpty(Stack* st){
	return (st->top == NULL);
}

void stackDestroy(Stack* st){
	if(st!= NULL){
		while(st->top!= NULL){
			pop(st);
		}
	}
}

void display(Stack* st){
	Node* t = st->top;
	while(t!= NULL){
		printf("%d ",t->d);
		t = t->pNext;
	}
	printf("\n");
}

int main(){
	Stack* st = StackConstruct();
	push(st,1);
	push(st,2);
	push(st,3);
	push(st,4);
	display(st);
	printf("%d \n", top(st));
	printf("%d \n", pop(st));
	printf("%d \n", pop(st));
	printf("%d \n", pop(st));
	printf("%d \n", pop(st));
	printf("%d \n", pop(st));
	printf("%d \n", pop(st));
	printf("%d \n", pop(st));
	return 0;
}
