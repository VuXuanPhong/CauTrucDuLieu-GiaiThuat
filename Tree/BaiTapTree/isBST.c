// determine if tree is bst.
#include <stdio.h>
#include <stdlib.h>

struct _treeNode{
	int info;
	struct _treeNode* left;
	struct _treeNode* right;
};

typedef struct _treeNode TreeNode;

TreeNode* makeNewNode(int d);
int isBST(TreeNode* root);

int main(){
	TreeNode* root = makeNewNode(50);
	TreeNode* a = makeNewNode(30);
	TreeNode* b = makeNewNode(55);
	TreeNode* c = makeNewNode(25);
	TreeNode* d = makeNewNode(35);
	TreeNode* e = makeNewNode(53);
	TreeNode* f = makeNewNode(60);
	TreeNode* g = makeNewNode(10);
	TreeNode* h = makeNewNode(31);
	TreeNode* i = makeNewNode(37);
	TreeNode* j = makeNewNode(62);
	TreeNode* k = makeNewNode(20);
	root->left = a;
	root->right = b;
	a->left = c;
	a->right = d;
	c->left = g;
	g->right = k;
	d->left = h;
	d->right = i;
	b->right = f;
	b->left = e;
	f->right = j;
	int bst = isBST(root);
	printf("%d \n",bst);
	return 0;
}

TreeNode* makeNewNode(int d){
	TreeNode* t = NULL;
	t = (TreeNode*) malloc(sizeof(TreeNode));
	if(t==NULL){
		printf("Not enough memory. \n");
		exit(0);
	}
	t->info = d;
	t->left = NULL;
	t->right = NULL;
	return t;
}

int isBST(TreeNode* root){
	if(root == NULL) return 0;
	if(root->left == NULL && root->right == NULL) return 1;
	if(root->left == NULL && root->right!= NULL){
		if(root->right->info <= root->info) return 0;
		return isBST(root->right);
	}
	if(root->left!= NULL && root->right == NULL){
		if(root->left->info >= root->info) return 0;
		return isBST(root->left);
	}
	if(root->left!= NULL && root->right != NULL){
		if(root->right->info <= root->info) return 0;
		if(root->left->info >= root->info) return 0;
		int l = isBST(root->left);
		int r = isBST(root->right);
		return (l*r);
	}
}
