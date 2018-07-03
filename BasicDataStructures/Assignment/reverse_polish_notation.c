/*************************SOLVE DATA STRUCTURES PROBLEM*******************************
When            Who         What
30/04/2018      Phong      Assignment Basic Data Structures

*************************************************************************************/

/*
** Description:
Infix to Postfix.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define inf '.'
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

// method Stack:
Node* makeNewNode(data d);
Stack* StackConstruct();
void push(Stack* st, data d);
data pop(Stack* st);
data top(Stack* st);
int isEmpty(Stack* st);
void stackDestroy(Stack* st);
void display(Stack* st);

// method Infix to Postfix.

char c[] = { '+', '-', '*', '/', '^' };
int u[] = { 1, 1, 2, 2, 3 };

int douutien(char ch){
	int i = 0;
	for (; i<5; i++){
		if (c[i] == ch) return u[i];
	}
	return -1;
}

char* infixToPostfix(char* s){
	int len = strlen(s);
	char* ps = NULL;
	ps = (char*)malloc((len + 1)*sizeof(char));
	Stack* st = StackConstruct();
	int i = 0;
	int j = 0;
	for (; i<len; i++){
		if (s[i] == '('){
			push(st, s[i]);
		}
		else if (s[i] == ')'){
			while (top(st) != '(' && top(st) != '.'){
				ps[j++] = (char)pop(st);
			}
			pop(st);
		}
		else if (s[i] >= '0' && s[i] <= '9'){
			ps[j++] = s[i];
		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '*'|| s[i] == '^'){
			if (s[i] == '^') push(st, '^');
			else if (douutien(s[i]) <= douutien((char)top(st))){
				while (douutien(s[i]) <= douutien((char)top(st))){
					ps[j++] = (char)pop(st);
				}
				push(st, s[i]);
			}
			else push(st, s[i]);
		}
	}
	while (st->size != 0){
		ps[j++] = pop(st);
	}
	ps[j] = 0;
	return ps;
}

int cal(int c1, int c2, char op){
	switch(op){
		case '+':
			return (c1+c2 );
		case '-':
			return c1 - c2;
		case '*':
			return (c1)*(c2);
		case '/':
			return (c1)/(c2);
		case '^':
			return pow(c1,c2);
		default:
			return 0;		
	}
}

int calPostfix(char* ps){
 	Stack* st = StackConstruct();
 	int i =0, len = strlen(ps);
 	for(;i<len;i++){
 		if(ps[i]>='0' && ps[i]<='9'){
 			push(st,ps[i]-48);
		}
		else if(ps[i]=='+'||ps[i]=='-'||ps[i]=='*'||ps[i]=='/'||ps[i]=='^'){
			int c2 = pop(st);
			int c1 = pop(st);
			int d = cal(c1,c2,ps[i]);
			push(st,d);
		}	
	}
	return top(st);
}


int main(){
	char s[100];
	gets(s);
	char* ps = infixToPostfix(s);
	printf("%s \n", ps);
	int d = calPostfix(ps);
	printf("%d \n",d);
	getchar();
	return 0;
}

Node* makeNewNode(data d){
	Node* t = NULL;
	t = (Node*)malloc(sizeof(Node));
	if (t == NULL){
		printf("Not enough memori.\n");
		exit(0);
	}
	t->d = d;
	t->pNext = NULL;
	return t;
}

Stack* StackConstruct(){
	Stack* st = NULL;
	st = (Stack*)malloc(sizeof(Stack));
	if (st == NULL){
		printf("Not enough memory.\n");
		exit(0);
	}
	st->top = NULL;
	st->size = 0;
	return st;
}

void push(Stack* st, data d){
	if (st == NULL) {
		printf("Stack is NULL");
		return;
	}
	Node* t = makeNewNode(d);
	t->pNext = st->top;
	st->top = t;
	st->size++;
}

data pop(Stack* st){
	if (st == NULL || st->top == NULL) return inf;
	Node* t = st->top;
	st->top = t->pNext;
	t->pNext = NULL;
	data d = t->d;
	free(t);
	st->size--;
	return d;
}

data top(Stack* st){
	if (st == NULL || st->top == NULL) return inf;
	return st->top->d;
}

int isEmpty(Stack* st){
	return (st->top == NULL);
}

void stackDestroy(Stack* st){
	if (st != NULL){
		while (st->top != NULL){
			pop(st);
		}
	}
}

void display(Stack* st){
	Node* t = st->top;
	while (t != NULL){
		printf("%d ", t->d);
		t = t->pNext;
	}
	printf("\n");
}

