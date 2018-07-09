// is all nodes of tree have value < key.  
#include <stdio.h>
#include <stdlib.h>

struct treeNode{
	int info;
	struct treeNode* left;
	struct treeNode* right;
};

typedef struct treeNode TreeNode;

TreeNode* makeNewNode(int d);
int isLeft(TreeNode* root, int key);

int main(){
	TreeNode* root = makeNewNode(50);
	TreeNode* a = makeNewNode(30);
	TreeNode* b = makeNewNode(55);
	TreeNode* c = makeNewNode(25);
	TreeNode* d = makeNewNode(35);
	TreeNode* e = makeNewNode(53);
	TreeNode* f = makeNewNode(62);
	TreeNode* g = makeNewNode(10);
	TreeNode* h = makeNewNode(31);
	TreeNode* i = makeNewNode(37);
	TreeNode* j = makeNewNode(63);
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
	int dd = isLeft(root,30);
	printf("%d \n",dd);
	return 0;
}

int isLeft(TreeNode* root, int key){
	if(root == NULL) return 0;
	if(root->info >= key) return 0;
	if(root->left == NULL && root->right == NULL){
		if(root->info < key) return 1;
		else return 0;
	}
	if(root->left != NULL && root->right == NULL){
		return isLeft(root->left,key);
	}
	if(root->left == NULL && root->right != NULL){
		return isLeft(root->right,key);
	}
	if(root->left != NULL && root->right != NULL){
		return isLeft(root->right,key)*isLeft(root->left,key);
	}
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
