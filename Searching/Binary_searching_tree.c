#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct _treeNode {
	float inf;
	struct _treeNode* leftPtr;
	struct _treeNode* rightPtr;
	struct _treeNode* parent;
};

typedef struct _treeNode TreeNode;

// function
TreeNode* makeTreeNode(float value);
TreeNode* findMin(TreeNode* T);
TreeNode* findMax(TreeNode* T);
TreeNode* insert(TreeNode* T, float item);
TreeNode* search(TreeNode* T, float item);
TreeNode* deleteT(TreeNode* T, float item);
void printInorder(const TreeNode* nodePtr);
void printPreorder(const TreeNode* nodePtr);
void printPostorder(const TreeNode* nodePtr);

int main(){
	TreeNode* tree = NULL;
	tree = insert(tree,50);
	tree = insert(tree,30);	
	tree = insert(tree,55);	
	tree = insert(tree,25);	
	tree = insert(tree,35);	
	tree = insert(tree,53);	
	tree = insert(tree,10);	
	tree = insert(tree,31);	
	tree = insert(tree,37);	
	tree = insert(tree,62);	
	tree = insert(tree,20);
	printInorder(tree);
	printf("\n");
	TreeNode* nodeMax = findMax(tree);
	printf("%.1f \n",nodeMax->inf);
	TreeNode* nodeMin = findMin(tree);
	printf("%.1f \n",nodeMin->inf); 
	getch();
	return 0;
}

TreeNode* makeTreeNode(float value){
	TreeNode* treeNode = NULL;
	treeNode = (TreeNode*) malloc(sizeof(TreeNode));
	if(treeNode == NULL){
		printf("Bo nho day \n");
		exit(1);
	}
	else{
		treeNode->inf = value;
		treeNode->leftPtr = NULL;
		treeNode->rightPtr = NULL;
		treeNode->parent = NULL;
	}
	return treeNode;
}

TreeNode* findMin(TreeNode* T){
	if(T == NULL) return NULL;
	else{
		if(T->leftPtr == NULL) return T;
		else return findMin(T->leftPtr);
	}
}

TreeNode* findMax(TreeNode* T){
	if(T == NULL) return NULL;
	else{
		if(T->rightPtr == NULL) return T;
		else return findMax(T->rightPtr);
	}
}
TreeNode* insert(TreeNode* T, float item){
	if(T == NULL){
		T = makeTreeNode(item);
	}
	else{
		if(item > T->inf){
		 	T->rightPtr = insert(T->rightPtr,item);
			T->rightPtr->parent = T;
		}
		if(item < T->inf) {
			T->leftPtr = insert(T->leftPtr,item);
			T->leftPtr->parent = T;
		}
	}
	return T;
}

TreeNode* search(TreeNode* T, float item){
	if(T!= NULL){
		if(item > T->inf){
			search(T->rightPtr,item);
		}
		if(item < T->inf){
			search(T->leftPtr,item);
		}
	}
	return T;
}

void printInorder(const TreeNode* nodePtr){
	if(nodePtr!= NULL){
		printInorder(nodePtr->leftPtr);
		printf("%.1f ",nodePtr->inf);
		printInorder(nodePtr->rightPtr);	
	}
}

void printPreorder(const TreeNode* nodePtr){
	if(nodePtr!= NULL){
		printf("%.1f ",nodePtr->inf);
		printPreorder(nodePtr->leftPtr);
		printPreorder(nodePtr->rightPtr);	
	}
}

void printPostorder(const TreeNode* nodePtr){
	if(nodePtr!= NULL){
		printPostorder(nodePtr->leftPtr);
		printPostorder(nodePtr->rightPtr);
		printf("%f",nodePtr->inf);	
	}
}


TreeNode* deleteT(TreeNode* T, float item){
	if(T==NULL) printf("Not found \n");
	else if(item > T->inf) T->rightPtr = deleteT(T->rightPtr, item);
	else if(item < T->inf) T->leftPtr = deleteT(T->leftPtr,item);
	else{
		if(T->leftPtr && T->rightPtr){
			TreeNode* temp = findMin(T->rightPtr);
			float a = T->inf;
			T->inf = temp->inf;
			temp->inf = a;
			T->rightPtr = deleteT(T->rightPtr,item);
		}
		else{
			TreeNode* temp = T;
			if(T->leftPtr == NULL){
				T = T->rightPtr;
			}
			if(T->rightPtr == NULL){
				T = T->leftPtr;
			}
			free(temp);
		}
	}
}

