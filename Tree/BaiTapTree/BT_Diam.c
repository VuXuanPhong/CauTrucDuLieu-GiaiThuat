// The longest path of a tree is longest path between two leaf node.
// The longest path of a tree is number of node on this path.
// Find The longest path of a tree.
#include <stdio.h>
#include <stdlib.h>

struct _treeNode{
	int info;
	struct _treeNode* left;
	struct _treeNode* right;
};

typedef struct _treeNode TreeNode;
TreeNode* makeNewNode(int d);
int BT_Diam(TreeNode* root);
int depth(TreeNode* tree);


int main(){
	TreeNode* root = makeNewNode(1);
	TreeNode* a = makeNewNode(1);
	TreeNode* b = makeNewNode(1);
	TreeNode* c = makeNewNode(1);
	TreeNode* d = makeNewNode(1);
	TreeNode* e = makeNewNode(1);
	TreeNode* f = makeNewNode(1);
	TreeNode* g = makeNewNode(1);
	TreeNode* h = makeNewNode(1);
	TreeNode* i = makeNewNode(1);
	TreeNode* j = makeNewNode(1);
	TreeNode* k = makeNewNode(1);
	TreeNode* l = makeNewNode(1);
	TreeNode* m = makeNewNode(1);
	TreeNode* n = makeNewNode(1);
	root->left = a;
	root->right = b;
	a->left = c;
	a->right = d;
	b->right = e;
	c->left = f;
	c->right = g;
	f->right = h;
	h->left = j;
	h->right = k;
	k->right = n;
	g->left = i;
	i->left = l;
	i->right = m;
	int dd = BT_Diam(root);
	printf("%d \n",dd);
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

int depth(TreeNode* tree){
	if(tree == NULL) return 0;
	int ld = depth(tree->left);
	int rd = depth(tree->right);
	return 1 +(ld>rd?ld:rd);
}


int BT_Diam(TreeNode* root){
	if(root==NULL) return 0;
	if(root->left == NULL && root->right == NULL) return 1;
	int l = depth(root->left);
	int r = depth(root->right);
	int d = l + r +1;
	int ld = BT_Diam(root->left);
	int rd = BT_Diam(root->right);
	int max = d;
	if(ld > max) max = ld;
	if(rd > max) max = rd;
	return max;
}
