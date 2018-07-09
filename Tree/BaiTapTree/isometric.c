#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tnode{
	int data;
	struct Tnode* left;
	struct Tnode* right;
};

typedef struct Tnode BTNode;
BTNode* makeNewNode(int d);
int isometric(BTNode* T1, BTNode* T2);

int main(){
	BTNode* T1 = makeNewNode(1);
	BTNode* a = makeNewNode(2);
	BTNode* b = makeNewNode(3);
	BTNode* c = makeNewNode(4);
	BTNode* d = makeNewNode(5);
	BTNode* e = makeNewNode(6);
	BTNode* f = makeNewNode(7);
	T1->left = a;
	T1->right = b;
	a->left = c;
	a->right = NULL;
	c->left = NULL;
	c->right = e;
	b->left = d;
	b->right = NULL;
	d->left = NULL;
	d->right = f;
	BTNode* T2 = makeNewNode(1);
	BTNode* a1 = makeNewNode(2);
	BTNode* b1 = makeNewNode(3);
	BTNode* c1 = makeNewNode(4);
	BTNode* d1 = makeNewNode(5);
	BTNode* e1 = makeNewNode(6);
	BTNode* f1 = makeNewNode(7);
	T2->left = a1;
	T2->right = b1;
	a1->left = c1;
	a1->right = NULL;
	c1->left = NULL;
	c1->right = NULL;
	b1->left = d1;
	b1->right = NULL;
	d1->left = NULL;
	d1->right = f1;
	printf("%d \n", isometric(T1, T2));
	return 0;
}

int isometric(BTNode* T1, BTNode* T2){
	if (T1 == NULL && T2 == NULL) return 1;
	if (T1 != NULL && !T2) return 0;
	if (T2 != NULL && !T1) return 0;
	int a = isometric(T1->left, T2->left);
	int b = isometric(T1->right, T2->right);
	if (a == 0 || b == 0) return 0;
	else return 1;
}

BTNode* makeNewNode(int d){
	BTNode* t = NULL;
	t = (BTNode*)malloc(sizeof(BTNode));
	if (!t) {
		printf("Not enough memory.\n");
		exit(0);
	}
	t->data = d;
	t->left = NULL;
	t->right = NULL;
	return t;
}

