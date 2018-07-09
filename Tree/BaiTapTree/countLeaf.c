// find number of leaf of binary tree
// calculation sum of odd node.
#include <stdio.h>
#include <stdlib.h>

struct Tnode{
	int key;
	struct Tnode* left;
	struct Tnode* right;
};

typedef struct Tnode treeNode;

int countLeaf(treeNode* rootTree);
int OddSum(treeNode* root);
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
	int k = countLeaf(root);
	printf("%d \n",k);
	int oddSum = OddSum(root);
	printf("%d \n",oddSum);
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

int countLeaf(treeNode* rootTree){
	if(rootTree == NULL) return 0;
	if(rootTree->left == NULL && rootTree->right == NULL) return 1;
	return countLeaf(rootTree->left) + countLeaf(rootTree->right);
}

int OddSum(treeNode* root){
	if(root == NULL) return 0;
	int s = 0; 
	if(root->key &1) s += root->key;
	s+= OddSum(root->left);
	s+= OddSum(root->right);
	return s;
}

