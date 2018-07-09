// find max even element in Binary searching tree.
#include <stdio.h>
#include <stdlib.h>

struct _treeNode{
	int info;
	struct _treeNode* left;
	struct _treeNode* right;
};

typedef struct _treeNode TreeNode;

TreeNode* makeNewNode(int d);
int EvenMax(TreeNode* root);

int main(){
	TreeNode* root = makeNewNode(51);
	TreeNode* a = makeNewNode(31);
	TreeNode* b = makeNewNode(55);
	TreeNode* c = makeNewNode(25);
	TreeNode* d = makeNewNode(35);
	TreeNode* e = makeNewNode(53);
	TreeNode* f = makeNewNode(61);
	TreeNode* g = makeNewNode(11);
	TreeNode* h = makeNewNode(31);
	TreeNode* i = makeNewNode(37);
	TreeNode* j = makeNewNode(63);
	TreeNode* k = makeNewNode(21);
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
	int evenMax = EvenMax(root);
	printf("%d \n",evenMax);
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

int EvenMax(TreeNode* root){
	if(root == NULL) return -1;
	if(root->left == NULL && root->right == NULL){
		if(root->info &1) return -1;
		return root->info;
	}
	int d = -1;
	d = EvenMax(root->right);
	if(d == -1){
		if(!(root->info&1)) return root->info;
		d = EvenMax(root->left);
	}
	return d;
}

