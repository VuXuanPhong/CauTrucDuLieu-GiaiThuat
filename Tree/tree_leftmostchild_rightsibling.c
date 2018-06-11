/*************************SOLVE TREE PROBLEM****************************************
When            Who         What
14/04/2018      Phong      Bieu dien cay tong quat su dung con trai va em ke can phai

*************************************************************************************/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef char Label;

typedef struct _Tnode{
	Label lbl;
	struct _Tnode* leftmost_child;
	struct _Tnode* right_sibling;
} TreeNode;

TreeNode* makeNewTreeNode(Label c){
	TreeNode* temp = NULL;
	temp = (TreeNode*) malloc(sizeof(TreeNode));
	if(temp == NULL){
		printf("Bo nho day \n");
		exit(0);
	}
	temp->lbl = c;
	temp->leftmost_child = NULL;
	temp->right_sibling = NULL;
	return temp;
}

// DUYET THEO THU TU TRUOC
void preOrder(TreeNode* tree){
	if(tree == NULL){
		return;
	}
	printf("%c ", tree->lbl);
	TreeNode* p = tree->leftmost_child;
	while(p!= NULL){
		preOrder(p);
		p = p->right_sibling;
	}
	//printf("\n");
}

//DUYET THEO THU TU SAU
void postOrder(TreeNode* tree){
	if(tree == NULL) return;
	TreeNode* p = tree->leftmost_child;
	while(p != NULL){
		postOrder(p);
		p = p->right_sibling;
	}
	printf("%c ", tree->lbl);
}

// DUYET THEO THU TU GIUA
void inorder(TreeNode* tree){
	if(tree == NULL) return;
	TreeNode* p = tree->leftmost_child;
	inorder(p);
	printf("%c ", tree->lbl);
	if(p!= NULL){
		p = p->right_sibling;
	}
	while(p!= NULL){
		inorder(p);
		p = p->right_sibling;
	}
	
	//printf("\n");
}

TreeNode* isChildOfParent(TreeNode* parent, TreeNode* node){
	if(parent->leftmost_child == NULL) return NULL;
	TreeNode* p = parent->leftmost_child;
	while(p != NULL){
		if(p->lbl == node->lbl) return parent;
		else p = p->right_sibling;
	}
	p = parent->leftmost_child;
	while(p != NULL){
		TreeNode* temp = isChildOfParent(p,node);
		if(temp != NULL) return temp;
		else p = p->right_sibling;
	}
	return NULL;
}

TreeNode* parent(TreeNode* tree, TreeNode* node){
	if(tree == NULL) return NULL;
	if(tree->lbl == node->lbl) return NULL;
	TreeNode* temp = isChildOfParent(tree, node);
	return temp;
}

TreeNode* leftmost_child(TreeNode* node, TreeNode* tree){
	if(tree->leftmost_child == NULL) return NULL;
	if(node->lbl == tree->lbl) return tree->leftmost_child;
	TreeNode* p = tree->leftmost_child;
	while(p != NULL){
		TreeNode* temp = leftmost_child(node,p);
		if(temp != NULL) return temp; 
		else p = p->right_sibling;
	}
	return NULL;
}

TreeNode* right_sibling(TreeNode* node, TreeNode* tree){
	if(tree == NULL) return NULL; 
	if(node->lbl == tree->lbl) return tree->right_sibling;
	TreeNode* p = tree->leftmost_child;
	while(p != NULL){
		//printf("%c \n",p->lbl);
		TreeNode* temp = right_sibling(node,p);
		if(temp != NULL) return temp;
		else p = p->right_sibling;
	}
	return NULL;
}

Label label(TreeNode* node){
	return node->lbl; 
}

void makeNull(TreeNode** tree){
	if((*tree)->leftmost_child == NULL && (*tree)->right_sibling == NULL) free((*tree));
	if((*tree)->right_sibling == NULL){
		TreeNode* p = (*tree)->leftmost_child;
		(*tree)->leftmost_child = NULL;
		free((*tree));
		(*tree) = NULL;
		while(p!= NULL){
			TreeNode* temp = p;
			p = p->right_sibling;
			temp->right_sibling = NULL;
			makeNull(&temp);
		}
	}
}

int numOfNodeHasLess3Child(TreeNode* tree){
	if(tree->leftmost_child == NULL) return 1;
	else{
		int dem = 0;
		TreeNode* temp = tree->leftmost_child;
		int sum = 0;
		while(temp!= NULL){
			dem++;
			sum += numOfNodeHasLess3Child(temp);
			temp = temp->right_sibling;
		}
		if(dem < 3) return sum+1;
		else return sum;
	}
}

int main(){
	
	TreeNode* nodeA = makeNewTreeNode('A');
	TreeNode* nodeB = makeNewTreeNode('B');
	TreeNode* nodeC = makeNewTreeNode('C');
	TreeNode* nodeD = makeNewTreeNode('D');
	TreeNode* nodeE = makeNewTreeNode('E');
	TreeNode* nodeF = makeNewTreeNode('F');
	TreeNode* nodeG = makeNewTreeNode('G');
	TreeNode* nodeH = makeNewTreeNode('H');
	TreeNode* nodeI = makeNewTreeNode('I');
	TreeNode* nodeJ = makeNewTreeNode('J');
	TreeNode* nodeK = makeNewTreeNode('K');
	
	TreeNode* root = nodeA;
	root->leftmost_child = nodeB;
	nodeB->leftmost_child = nodeE;
	nodeB->right_sibling = nodeC;
	nodeC->leftmost_child = nodeG;
	nodeC->right_sibling = nodeD;
	nodeE->right_sibling = nodeF;
	nodeG->leftmost_child = nodeH;
	nodeH->right_sibling = nodeI;
	nodeI->right_sibling = nodeJ;
	nodeJ->right_sibling = nodeK;
	
	printf("Duyet cay theo thu tu truoc: \n");
	preOrder(root);
	printf("\n");
	printf("Duyet cay theo thu tu sau: \n");
	postOrder(root);
	printf("\n");
	printf("Duyet cay theo thu tu giua: \n");
	inorder(root);
	printf("\n");
	
	TreeNode* parentOfNodeD = parent(root,nodeD);
	if(parentOfNodeD != NULL)
		printf("Node cha cua node D la %c \n",parentOfNodeD->lbl);
	
	TreeNode* leftmostofnodeG = leftmost_child(nodeG,root);
	if(leftmostofnodeG != NULL)
		printf("Con trai nhat cua node G la %c \n",leftmostofnodeG->lbl);
	
	TreeNode* rightsiblingofnodeI = right_sibling(nodeI,root);
	if(rightsiblingofnodeI != NULL)
		printf("Con trai nhat cua node I la %c \n",rightsiblingofnodeI->lbl);
	
	int d = numOfNodeHasLess3Child(root);
	printf("%d\n",d);
	
	makeNull(&root);
	if(root == NULL) printf("Yahoo");
	
	getch();
	return 0;
}
