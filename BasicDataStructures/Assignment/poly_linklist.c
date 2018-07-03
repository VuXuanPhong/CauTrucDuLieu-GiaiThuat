/*************************SOLVE DATA STRUCTURES PROBLEM*******************************
When            Who         What
29/04/2018      Phong      Assignment Basic Data Structures

*************************************************************************************/

/*
** Description:
	Sum and multi of two polys. 
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct _polyNode
{
	int coeff;
	int pow;
	struct _polyNode* next;
};

typedef struct _polyNode PolyNode;

PolyNode* makeNewPolyNode(int coeff, int pow){
	PolyNode* temp = NULL;
	temp = (PolyNode*)malloc(sizeof(PolyNode));
	if (temp == NULL){
		printf("Bo nho day \n");
		exit(0);
	}

	temp->coeff = coeff;
	temp->pow = pow;
	temp->next = NULL;
	return temp;
}

PolyNode* initAPoly(PolyNode* p){
	int i = 0;
	char c;
	
	while (1)
	{
		c = getchar();
		if (c == '\n') break;
		if (c < 48 || c>57) continue;
		int a = c - 48;
		if (a != 0){
			PolyNode* newNode = makeNewPolyNode(a, i);
			if (p == NULL){
				p = newNode;
			}
			else{
				PolyNode* temp = p;
				while (temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = newNode;
			}
		}
		i++;
		
	}

	return p;
}

void duyetPoly(PolyNode* p){
	PolyNode* temp = p;
	while (temp!= NULL)
	{
		printf("%dX%d ", temp->coeff, temp->pow);
		temp = temp->next;
	}
	printf("\n");
}

PolyNode* insert(PolyNode* p, int coeff, int pow){
	PolyNode* newNode = NULL;
	newNode = (PolyNode*)malloc(sizeof(PolyNode));
	if (newNode == NULL){
		printf("Bo nho day \n");
		exit(0);
	}
	newNode->coeff = coeff;
	newNode->pow = pow;
	newNode->next = NULL;
	if (p == NULL){
		p = newNode;
	}
	else{
		PolyNode* temp = p;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
	return p;
}

PolyNode* sumOfTwoPoly(PolyNode* poly1, PolyNode* poly2){

	PolyNode* temp1 = poly1;
	PolyNode* temp2 = poly2;
	PolyNode* sum = NULL;

	while (temp1!= NULL && temp2!= NULL)
	{
		if (temp1->pow < temp2->pow){
			sum =insert(sum, temp1->coeff, temp1->pow);
			temp1 = temp1->next;
		}
		else if (temp1->pow > temp2->pow){
			sum = insert(sum, temp2->coeff, temp2->pow);
			temp2 = temp2->next;
		}
		else
		{
			sum = insert(sum, temp2->coeff + temp1->coeff, temp2->pow );
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}
	
	while (temp1!= NULL)
	{
		sum = insert(sum, temp1->coeff, temp1->pow);
		temp1 = temp1->next;
	}
	
	while (temp2 != NULL)
	{
		sum = insert(sum, temp2->coeff, temp2->pow);
		temp2 = temp2->next;
	}
	return sum;
}

int powOfLast(PolyNode* p){
	PolyNode* temp = p;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return temp->pow;
}

PolyNode* mulOfTwoPoly(PolyNode* p1, PolyNode* p2){
	int sz = powOfLast(p1) + powOfLast(p2) + 1;
	int* a = NULL;
	a = (int*)calloc(sz,sizeof(int));
	if (a == NULL){
		printf("Bo nho day\n");
		exit(0);
	}
	PolyNode* temp1 = p1;
	PolyNode* temp2 = p2;

	while (temp1 != NULL){
	
		while (temp2!= NULL)
		{
			int coeff = temp1->coeff * temp2->coeff;
			int pow = temp1->pow + temp2->pow;
			a[pow] += coeff;
			temp2 = temp2->next;
		}

		temp2 = p2;
		temp1 = temp1->next;
	}

	PolyNode* mul = NULL;
	int i = 0;
	for (; i < sz; i++){
		if (a[i] != 0){
			mul = insert(mul, a[i], i);
		}
	}
	return mul;
}

int main(){
	
	PolyNode* poly1 = NULL;
	poly1 = initAPoly(poly1);
	printf("Dang cua Poly1: ");
	duyetPoly(poly1);

	PolyNode* poly2 = NULL;
	poly2 = initAPoly(poly2);
	printf("Dang cua Poly2: ");
	duyetPoly(poly2);

	PolyNode* sum = sumOfTwoPoly(poly1, poly2);
	printf("Poly1 + Poly2 = ");
	duyetPoly(sum);

	PolyNode* mul = mulOfTwoPoly(poly1, poly2);
	printf("Poly1 * Poly2 = ");
	duyetPoly(mul);
	getch();
	return 0;
}
