/*************************SOLVE DATA STRUCTURES PROBLEM*******************************
When            Who         What
29/04/2018      Phong      Assignment Basic Data Structures

*************************************************************************************/

/*
** Description:
	Convert Dec to b 
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

typedef char Item;

struct _stackNode
{
	Item data;
	struct _stackNode* next;
};

typedef struct _stackNode StackNode;

struct _stack
{
	struct _stackNode * top;
};

typedef struct _stack Stack;

char* S = "123456789ABCDEF"; // su dung de chuyen sang co so 16
Stack* s = NULL;
int szofStack = 0; // kich thuoc Stack
Stack* StackContructor(){
	Stack* s = NULL;
	s = (Stack*)malloc(sizeof(Stack));
	if (s == NULL){
		printf("Khong the cap phat bo nho cho Stack \n");
		exit(0);
	}
	s->top = NULL;
	return s;
}

int StackPush(Stack* s, int element){
	if (s == NULL){
		printf("Stack chua duoc cap phat \n");
		return 0;
	}
	StackNode* node = NULL;
	node = (StackNode*)malloc(sizeof(StackNode));
	if (node == NULL){
		printf("Bo nho khong du \n");
		return 0;
	}
	node->data = element;
	node->next = s->top;
	s->top = node;
	szofStack++;
	return 1;
}

Item StackPop(Stack* s){
	if (s == NULL){
		printf("Stack chua duoc cap phat \n");
		return NULL;
	}
	if (s->top == NULL){
		printf("Ngan xep rong \n");
		return NULL;
	}
	StackNode* node = s->top;
	Item data = node->data;
	s->top = node->next;
	free(node);
	szofStack--;
	return data;
}

void Disp(const Stack* s){
	if (s == NULL){
		printf("Stack chua duoc cap phat bo nho \n");
		return;
	}
	if (s->top == NULL){
		printf("Stack empty \n");
		return;
	}

	StackNode* temp = s->top;
	printf("Cac phan tu ngan xep la: \n");
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}

	printf("\n");
}

int StackEmpty(const Stack* s){
	return (s->top == NULL);
}

void StackDestroy(){
	while (!StackEmpty(s)){
		StackPop(s);
	}
	free(s);
}

int StackSize(const Stack* s){
	return szofStack;
}

char* convertToBRadix(int n, int b){
	while (n != 0)
	{
		int x = n%b;
		StackPush(s, x);
		n = n / b;
	}
	char* bRadix = NULL;
	bRadix = (char*)malloc(StackSize(s)*sizeof(char));
	if (bRadix == NULL){
		printf("Khong du bo nho \n");
		return NULL;
	}
	int i = 0;
	while (!StackEmpty(s))
	{
		int c = StackPop(s);
		if (b == 16){
			*(bRadix + i) = S[c - 1];
		}
		else *(bRadix + i) = c + 48;
		i++;
	}
	bRadix[i] = NULL;
	return bRadix;
}

int main(){
	int number = 3553; // a number in Dec
	int b = 16; // to b 
	
	s = StackContructor();
	char* a = convertToBRadix(number, b);
	printf("%s", a);
	getch();
	return 0;
}
