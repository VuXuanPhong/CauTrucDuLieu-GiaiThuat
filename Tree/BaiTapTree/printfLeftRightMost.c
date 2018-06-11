#include <stdio.h>
#include <stdlib.h>

struct _treeNode{
	int inf;
	struct _treeNode* left;
	struct _treeNode* right;
};
typedef struct _treeNode TreeNode;

TreeNode* makeTreeNode(int inf){
	TreeNode* temp = NULL;
	temp = (TreeNode*) malloc(sizeof(TreeNode));
	if(temp == NULL){
		printf("Bo nho day\n");
		exit(0);
	}
	temp->inf = inf;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
void printPreoder(TreeNode* root){
	if(root!=NULL){
		printf("%d ",root->inf);
		printPreoder(root->left);
		printPreoder(root->right);
	}
}

void printLeftRightMost(TreeNode* root){
	if(root == NULL) return;
	if(root->left == NULL && root->right == NULL){
		printf("%d ",root->inf);
	}
	else{
		printLeftRightMost(root->right);
		printLeftRightMost(root->left);
	}
}

int nodeHasTwoChild(TreeNode* tree){
	if(tree->left != NULL && tree->right != NULL){
		return 1+nodeHasTwoChild(tree->left)+nodeHasTwoChild(tree->left);
	}
	else return 0;
}

void inCucTriDiaPhuong(TreeNode* root, TreeNode* parent){
	if(root == NULL) return;
	if(parent!= NULL){
		if(root->left == NULL && root->right == NULL){
			if(root->inf < parent->inf) printf("%d\n",root->inf);
		}
		else if(root->left != NULL && root->right == NULL){
			int a = root->inf;
			int b = root->left->inf;
			int c = parent->inf;
			if(a < b && a < c) printf("%d\n",a);
		}
		else if(root->left == NULL && root->right != NULL){
			int a = root->inf;
			int b = root->right->inf;
			int c = parent->inf;
			if(a < b && a < c) printf("%d\n",a);
		}
		else{
			int a = root->inf;
			int b = root->right->inf;
			int c = root->left->inf;
			int d = parent->inf;
			if(a < b && a < c && a<d) printf("%d\n",a);
		}
	}
	else{
		if(root->left == NULL && root->right == NULL){
			printf("%d\n",root->inf);
		}
		else if(root->left != NULL && root->right == NULL){
			int a = root->inf;
			int b = root->left->inf;
			if(a < b) printf("%d\n",a);
		}
		else if(root->left == NULL && root->right != NULL){
			int a = root->inf;
			int b = root->right->inf;
			if(a < b) printf("%d\n",a);
		}
		else{
			int a = root->inf;
			int b = root->right->inf;
			int c = root->left->inf;
			if(a < b && a < c) printf("%d\n",a);
		}
	}
	inCucTriDiaPhuong(root->left,root);
	inCucTriDiaPhuong(root->right,root);
}

int main(){
	TreeNode* root = makeTreeNode(25);
	root->left = makeTreeNode(12);
	root->left->left = makeTreeNode(7);
	root->left->right = makeTreeNode(21);
	root->left->left->right = makeTreeNode(10);
	root->right =  makeTreeNode(36);
	root->right->right =  makeTreeNode(45);
	root->right->left =  makeTreeNode(31);
	root->right->left->left =  makeTreeNode(27);
	printPreoder(root);
	printf("\n");
	//printLeftRightMost(root);
	inCucTriDiaPhuong(root,NULL);
	int d = nodeHasTwoChild(root);
	printf("%d\n",d);
	return 0;
}
