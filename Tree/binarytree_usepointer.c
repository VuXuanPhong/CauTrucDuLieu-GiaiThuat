/*************************SOLVE TREE PROBLEM******************************************
When            Who         What
15/04/2018      Phong      Bieu dien binary tree su dung con tro

*************************************************************************************/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h>

struct Tnode{
	char word[20];
	struct Tnode* left;
	struct Tnode* right;
};

typedef struct Tnode treeNode;

struct _QueueNode{
	treeNode* tree;
	struct _QueueNode* next;
};

typedef struct _QueueNode QueueNode;

struct _QueueTree{
	QueueNode* front;
	QueueNode* rear;
	int size;
}; 



typedef struct _QueueTree QueueTree;


treeNode* makeTreeNode(char* word);
treeNode* RandomInsert(treeNode* tree, char* word);
void freeTree(treeNode* tree);
void printPreorder(treeNode* tree);
void printPostorder(treeNode* tree);
void printInorder(treeNode* tree);
int countNodes(treeNode* tree);
int depth(treeNode* tree);
treeNode* taocaynhiphandaydu(int n, char* X); // n la do sau
int kiemtracaynhiphandaydu(treeNode* tree);
treeNode* taocaynhiphanhoanchinh(int n, char* X); // n la so node
int kiemtracaynhiphanhoanchinh(treeNode* tree);


// Queue su dung trong thuat toan tao cay hoan chinh
QueueTree* queueTree0 = NULL;
QueueTree* init();

QueueNode* makeQueueNode(treeNode* tree);

void enqueueTree(QueueTree** queueTree,treeNode* tree);

QueueNode* dequeue(QueueTree* queueTree);

void freeQueueTree(QueueTree* queueTree);

int main(){
	treeNode* randomTree = NULL;
	char word[20] = "a";
	srand(time(NULL));
	while(strcmp(word,"~")!= 0){
		printf("\nEnter item (~ to finish): ");
		scanf("%s",word);
		if(strcmp(word,"~") == 0){
			printf("Cham dut nhap thong tin nut ... \n");
		}
		else randomTree = RandomInsert(randomTree, word);
	}
	
	printf("The tree in preorder: \n");
	printPreorder(randomTree);
	printf("\n*************************************************\n");
	
	printf("The tree in postorder: \n");
	printPostorder(randomTree);
	printf("\n*************************************************\n");
	
	printf("The tree in inorder: \n");
	printInorder(randomTree);
	printf("\n*************************************************\n");
	
	printf("The number of nodes is: %d \n", countNodes(randomTree));
	printf("The depth of the tree is: %d \n", depth(randomTree));
	
	//freeTree(randomTree);
	
	treeNode* tree = taocaynhiphandaydu(5,"Hell");
	if(kiemtracaynhiphandaydu(tree) == 1) {
		printf("tree la cay nhi phan day du \n");
	}	
	
	QueueTree* queueTree = init();
	enqueueTree(&queueTree,randomTree);
	enqueueTree(&queueTree,tree);
	printf("%d \n",queueTree->size);
	treeNode* tree1 = dequeue(queueTree)->tree;
	treeNode* tree2 = dequeue(queueTree)->tree;
	printf("%d \n",queueTree->size); 
	
	printf("\n");
	
	printf("The tree1 in preorder: \n");
	printPreorder(tree1);
	printf("\n*************************************************\n");
	
	printf("The tree2 in preorder: \n");
	printPreorder(tree2);
	printf("\n*************************************************\n");
	
	
	treeNode* cay1 = taocaynhiphanhoanchinh(5,"A");
	printf("\nThe cay1 in preorder: \n");
	printPreorder(cay1);
	printf("\n*************************************************\n");
	
	if(kiemtracaynhiphanhoanchinh(randomTree)==1){
		printf("Cay la hoan chinh \n");
	}
	
	if(kiemtracaynhiphanhoanchinh(cay1) == 1){
		printf("Cay 1 la cay hoan chinh \n");
	}
	
	if(kiemtracaynhiphanhoanchinh(tree) == 1){
		printf("Cay tree la cay hoan chinh \n");
	}
	
	
	
	
	getch();
	return 0;
}

treeNode* makeTreeNode(char* word){
	treeNode* newNode = NULL;
	newNode = (treeNode*) malloc(sizeof(treeNode));
	if(newNode == NULL){
		printf("Out of memory \n");
		exit(1);
	}
	else{
		newNode->left = NULL;
		newNode->right = NULL;
		strcpy(newNode->word,word);
	}
	return newNode;
}

treeNode* RandomInsert(treeNode* tree, char* word){
	treeNode* newNode;
	treeNode* p;
	
	newNode = makeTreeNode(word);
	if(tree == NULL) return newNode;
	if(rand()%2 == 0){
		p = tree;
		while(p->left != NULL) p = p->left;
		p->left = newNode;
		printf("Node %s is left child of %s \n",word,p->word);
	}
	else{
		p = tree;
		while(p->right!= NULL) p = p->right;
		p->right = newNode;
		printf("Node %s is right child of %s \n",word,p->word);
	}
	
	return tree;
}

void freeTree(treeNode* tree){
	if(tree == NULL) return;
	freeTree(tree->left);
	freeTree(tree->right);
	free(tree);
	return;
}

void printPreorder(treeNode* tree){
	if(tree != NULL){
		printf("%s ",tree->word);
		printPreorder(tree->left);
		printPostorder(tree->right);
	}
}

void printPostorder(treeNode* tree){
	if(tree != NULL){
		printPostorder(tree->left);
		printPostorder(tree->right);
		printf("%s ",tree->word);
	}	
}

void printInorder(treeNode* tree){
	if(tree != NULL){
		printInorder(tree->left);
		printf("%s ", tree->word);
		printInorder(tree->right);
	}	
}

int countNodes(treeNode* tree){
	if(tree == NULL) return 0;
	else{
		int ld = countNodes(tree->left);
		int rd = countNodes(tree->right);
		return 1+ld+rd;
	}
}

int depth(treeNode* tree){
	if(tree == NULL) return 0;
	int ld = depth(tree->left);
	int rd = depth(tree->right);
	return 1 +(ld>rd?ld:rd);
}

treeNode* taocaynhiphandaydu(int n, char* X){
	if(n == 0) return NULL;
	treeNode* r = makeTreeNode(X);
	treeNode* left = taocaynhiphandaydu(n-1,X);
	treeNode* right = taocaynhiphandaydu(n-1,X);
	r->left = left;
	r->right = right;
	return r;
}

int kiemtracaynhiphandaydu(treeNode* tree){
	if(tree == NULL) return 0;
	if(tree->left == NULL && tree->right == NULL) return 1;
	int i = kiemtracaynhiphandaydu(tree->left);
	int j = kiemtracaynhiphandaydu(tree->right);
	int hi = depth(tree->left);
	int hj = depth(tree->right);
	if((i==1)&&(j==1)&&(hi==hj)) return 1;
	else return 0;
}

QueueTree* init(){
	QueueTree* queueTree = NULL;
	queueTree = (QueueTree*) malloc(sizeof(QueueTree));
	if(queueTree == NULL){
		printf("Bo nho day\n");
		exit(1);
	}
	queueTree->front = NULL;
	queueTree->rear = NULL;
	queueTree->size = 0;
	return queueTree;
}

QueueNode* makeQueueNode(treeNode* tree){
	if(tree == NULL) return NULL;
	QueueNode* newQueueNode = NULL;
	newQueueNode = (QueueNode*) malloc(sizeof(QueueNode));
	if(newQueueNode == NULL) {
		printf("Bo nho day \n");
		exit(1);
	}
	newQueueNode->tree = tree;
	newQueueNode->next = NULL;
	return newQueueNode;
}

void enqueueTree(QueueTree** queueTree,treeNode* tree){
	QueueNode* queueNode = makeQueueNode(tree);
	if((*queueTree)->front == NULL){
		(*queueTree)->front = queueNode;
		(*queueTree)->rear = queueNode;
	}
	else{
		(*queueTree)->rear->next = queueNode;
		(*queueTree)->rear = queueNode;
	}
	(*queueTree)->size +=1;
}

QueueNode* dequeue(QueueTree* queueTree){
	if(queueTree == NULL) return NULL;
	if(queueTree->front == NULL) return NULL;
	queueTree->size -=1;
	QueueNode* temp = queueTree->front;
	queueTree->front = temp->next;
	temp->next = NULL;
	return temp;
}

treeNode* taocaynhiphanhoanchinh(int n, char* X){
	treeNode* tree = makeTreeNode(X);
	QueueTree* queueTree = init(); 
	enqueueTree(&queueTree,tree);
	int i = 1;
	while(i <= n){
		 printf("\nsize: %d",queueTree->size);
	 	 treeNode* temp = dequeue(queueTree)->tree;
	 	 if(temp == NULL) printf("wtf");
	 	 treeNode* aNode1 = makeTreeNode(X);
	 	 temp->left = aNode1;
		 i++;
	 	 if(i == n) break;
	 	 treeNode* aNode2 = makeTreeNode(X);
	 	 temp->right = aNode2;
		 i++;
	 	 if(i == n) break;
	 	 
	 	 enqueueTree(&queueTree,aNode1);
	 	 enqueueTree(&queueTree,aNode2);
	}
	return tree;
}

void freeQueueTree(QueueTree* queueTree){
	while(queueTree->size != 0){
		QueueNode* queueNode = dequeue(queueTree);
		free(queueNode);
		queueNode = NULL;
	}
}

int kiemtracaynhiphanhoanchinh(treeNode* tree){
	if(tree == NULL) return 0;
	if(tree->left == NULL && tree->right != NULL) return 0;
	if(tree->left == NULL && tree->right == NULL) return 1;
	int depthChildLeft = depth(tree->left);
	int depthChildRight = depth(tree->right);
	if(depthChildLeft - depthChildRight >= 2 || depthChildRight - depthChildLeft >= 1) return 0;
	if(depthChildLeft == depthChildRight){
		int i = kiemtracaynhiphandaydu(tree->left);
		int j = kiemtracaynhiphanhoanchinh(tree->right);
		if((i==1) &&(j==1)) return 1;
		else return 0;
	}
	if(depthChildLeft - depthChildRight == 1){
		int i = kiemtracaynhiphanhoanchinh(tree->left);
		int j = kiemtracaynhiphandaydu(tree->right);
		if((i==1)&&(j==1)) return 1;
		else return 0;
	}
}

