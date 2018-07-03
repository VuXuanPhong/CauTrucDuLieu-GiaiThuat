/*************************SOLVE DATA STRUCTURES PROBLEM*******************************
When            Who         What
29/04/2018      Phong      Assignment Basic Data Structure

*************************************************************************************/

/*
** Description:
	Pow use stack.
*/
#include <stdio.h>
#include <stdlib.h>

#define inf -1
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
// power
int power(int x, int n){
	Stack* st = StackConstruct();
	int temp = 1;
	while(n!=0){
		push(st,n);
		n = n/2;
	}
	while(st->size != 0){
		int a = pop(st);
		if(a&1){
			temp = temp*temp*x;
		}
		else{
			temp = temp*temp;
		}
	}
	return temp;
}
int main(){
	int d = power(2,5);
	printf("%d \n",d);
	return 0;
}
