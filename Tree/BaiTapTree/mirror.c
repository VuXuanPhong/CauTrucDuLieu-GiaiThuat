#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
};

typedef struct TreeNode BTree;
BTree* makeNewNode(int d);
BTree* mirror(BTree* nodePtr);

int main(){
	BTree* root = makeNewNode(1);
	BTree* a = makeNewNode(2);
	BTree* b = makeNewNode(3);
	BTree* c = makeNewNode(4);
	BTree* d = makeNewNode(5);
	BTree* e = makeNewNode(6);
	root->left = a;
	root->right = b;
	a->left = c;
	a->right = d;
	b->left = e;
	b->right = NULL;
	root = mirror(root);
	return 0;
}

BTree* mirror(BTree* nodePtr){
	if (nodePtr == NULL) return NULL;
	if (nodePtr->left == NULL && nodePtr->right == NULL) return nodePtr;
	BTree* t = nodePtr->left;
	nodePtr->left = nodePtr->right;
	nodePtr->right = t;
	BTree* left = mirror(nodePtr->left);
	BTree* right = mirror(nodePtr->right);
	nodePtr->left = left;
	nodePtr->right = right;
	return nodePtr;
}

BTree* makeNewNode(int d){
	BTree* t = NULL;
	t = (BTree*)malloc(sizeof(BTree));
	if (t == NULL) {
		printf("Not enough memory. \n");
		exit(0);
	}
	t->data = d;
	t->left = NULL;
	t->right = NULL;
	return t;
}
