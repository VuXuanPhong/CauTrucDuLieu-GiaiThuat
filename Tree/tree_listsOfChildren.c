/*************************SOLVE PERFORM TREE************************************
When            Who         What
14/04/2018      Phong      perform tree by lists of children  

*************************************************************************************/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef char label;

// type a node of tree 
typedef struct _NodeT{
	label lbl;
	struct NodeT* next;
} NodeT;

#define maxLength 100

// Tree
typedef struct _TreeT{
	NodeT* listChildren[maxLength];
	int leght;
} TreeT;

// create a new node of tree
NodeT* makeNewNode(char c){
	NodeT* temp = NULL;
	temp = (NodeT*) malloc(sizeof(NodeT));
	if(temp == NULL){
		printf("Bo nho day \n");
		exit(0);
	}	
	
	temp->lbl = c;
	temp->next = NULL;
}

// find left most child of node.
NodeT* leftmost_child(TreeT* tree, NodeT* node){
	int i =0;
	for(i =0; i< tree->leght; i++){
		if(tree->listChildren[i]->lbl == node->lbl){
			return tree->listChildren[i]->next;
		}
	}
	
	return NULL;
}
NodeT* parent(TreeT* tree, NodeT* t){
	int i =0;
	for(i =0; i< tree->leght; i++){
		NodeT* temp = tree->listChildren[i];
		temp = temp->next;
		while(temp != NULL){
			if(t->lbl ==  temp->lbl){
				return tree->listChildren[i];
			}
			temp = temp->next;
		}
	}
	
	return NULL;
}

NodeT* right_sibling(TreeT* tree, NodeT* node){
	int i =0;
	for(i=0; i< tree->leght; i++){
		NodeT* temp = tree->listChildren[i]->next;
		while(temp != NULL){
			if(temp->lbl == node->lbl){
				return temp->next;
			}
			temp = temp->next;
		}
	}
	return NULL;
}


NodeT* root(TreeT* tree){
	return tree->listChildren[0];
}

NodeT* deleteList(NodeT* list){
	NodeT* first = list;
	while(first != NULL){
		NodeT* temp = first;
		first = first->next;
		temp->next = NULL;
		free(temp);
	}
}

void makeNull(TreeT* tree){
	int i =0; 
	for(i=0; i<tree->leght; i++){
		deleteList(tree->listChildren[i]);
	}
	tree->leght = 0;
}

int main(){
	// init tree
	TreeT* tree = NULL;
	tree = (TreeT*) malloc(sizeof(TreeT));
	if(tree == NULL){
		printf("Bo nho day \n");
		exit(0);
	} 
	int i =0;
	for( i=0; i< maxLength; i++){
		tree->listChildren[i] = NULL;
		tree->listChildren[i] = (NodeT*) malloc(sizeof(NodeT));
		if(tree->listChildren[i] == NULL){
			printf("Bo nho day \n");
			exit(0);
		}
	}
	
	NodeT* node1 = makeNewNode('a');
	NodeT* node2 = makeNewNode('b');
	NodeT* node3 = makeNewNode('c');
	NodeT* node4 = makeNewNode('d');
	NodeT* node5 = makeNewNode('e');
	NodeT* node6 = makeNewNode('f');
	NodeT* node7 = makeNewNode('g');
	NodeT* node8 = makeNewNode('h');	
	NodeT* node9 = makeNewNode('i');
	NodeT* node10 = makeNewNode('j');
	
	tree->listChildren[0] = makeNewNode(node1->lbl);
	tree->listChildren[0]->next = node2;
	node2->next = node3;
	node3->next = NULL;
	
	tree->listChildren[1] = makeNewNode(node2->lbl);
	tree->listChildren[1]->next = node4;
	node4->next = node5;
	node5->next = NULL;
	
	tree->listChildren[2] = makeNewNode(node3->lbl);
	tree->listChildren[2]->next = node6;
	node6->next = node10;
	node10->next = NULL;
	
	tree->listChildren[3] = makeNewNode(node4->lbl);
	tree->listChildren[3]->next = NULL;
	
	
	tree->listChildren[4] = makeNewNode(node5->lbl);
	tree->listChildren[4]->next = NULL;
	
	tree->listChildren[5] = makeNewNode(node6->lbl);
	tree->listChildren[5]->next = node7;
	node7->next = node8;
	node8->next = node9;
	node9->next = NULL;
	
	tree->listChildren[6] = makeNewNode(node7->lbl);
	tree->listChildren[6]->next = NULL;
	
	tree->listChildren[7] = makeNewNode(node8->lbl);
	tree->listChildren[7]->next = NULL;
	
	tree->listChildren[8] = makeNewNode(node9->lbl);
	tree->listChildren[8]->next = NULL;
	
	tree->listChildren[9] = makeNewNode(node10->lbl);
	tree->listChildren[9]->next = NULL;
	
	tree->leght = 10;
	
	
	NodeT* leftmodechild_node2 = leftmost_child(tree,node2);
	printf("Left most child of node 2 (%c) la %c \n",node2->lbl, leftmodechild_node2->lbl);
	
	NodeT* parentOfNode5 = parent(tree,node5);
	printf("Parent of node 5 (%c) la %c \n",node5->lbl, parentOfNode5->lbl);
	
	NodeT* rightSiblingOfNode8 = right_sibling(tree,node8);
	printf("Right sibling of node 8 (%c) la %c \n",node8->lbl, rightSiblingOfNode8->lbl);
	
	
	
	getch();
	return 0;
}

