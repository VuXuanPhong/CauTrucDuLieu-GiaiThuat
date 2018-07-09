// find number of nodes have key bigger k.
#include <stdio.h>
#include <stdlib.h>

struct Tnode{
	int key;
	struct Tnode* left;
	struct Tnode* right;
};

typedef struct Tnode treeNode;

int countNodes(treeNode* rootTree, int k);
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
	int k = countNodes(root,2);
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

int countNodes(treeNode* rootTree, int k){
	if(rootTree == NULL) return 0;
	int d = 0;
	if(rootTree->key > k) d++;
	d+= countNodes(rootTree->left,k);
	d+= countNodes(rootTree->right,k);
	return d;
}


