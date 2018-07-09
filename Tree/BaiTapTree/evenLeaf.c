// find number of even leaf of binary tree.
#include <stdio.h>
#include <stdlib.h>

struct Tnode{
	int key;
	struct Tnode* left;
	struct Tnode* right;
};

typedef struct Tnode treeNode;

int evenLeaf(treeNode* rootTree);
treeNode* makeNewNode(int d);


int main(){
	treeNode* root = makeNewNode(1);
	treeNode* a = makeNewNode(2);
	treeNode* b = makeNewNode(3);
	treeNode* c = makeNewNode(4);
	treeNode* d = makeNewNode(5);
	treeNode* e = makeNewNode(6);
	root->left = a;
	root->right = b;
	a->left = c;
	a->right = d;
	b->left = e;
	b->right = NULL;
	int k = evenLeaf(root);
	printf("%d \n",k);
	return 0;
}

treeNode* makeNewNode(int d){
	treeNode* t = NULL;
	t = (treeNode*)malloc(sizeof(treeNode));
	if (!t) {
		printf("Not enough memory.\n");
		exit(0);
	}
	t->key = d;
	t->left = NULL;
	t->right = NULL;
	return t;
}


int evenLeaf(treeNode* rootTree){
	if(rootTree==NULL) return 0;
	if(rootTree->left == NULL && rootTree->right == NULL){
		if(rootTree->key & 1) return 0;
		else return 1;
	}
	int a = evenLeaf(rootTree->left);
	int b = evenLeaf(rootTree->right);
	return a+b;
}
