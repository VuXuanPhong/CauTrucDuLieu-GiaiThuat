/*************************SOLVE TREE PROBLEM******************************************
When            Who         What
06/05/2018      Phong      Ma hoa Huffman. 

*************************************************************************************/
/*
	Ma hoa Huffman dua tren hang doi uu tien.
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
// TreeNode
struct _TreeNode{
	char c;
	int freq;
	struct _TreeNode* left;
	struct _TreeNode* right;
};

typedef struct _TreeNode TreeNode;

TreeNode* makeNewTreeNode(char c, int freq){
	TreeNode* temp = NULL;
	temp = (TreeNode*) malloc(sizeof(TreeNode));
	if(temp == NULL){
		printf("Bo nho day \n");
		exit(1);
	}
	temp->c = c;
	temp->freq = freq;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

// PriorityQueue
#define maxlength 100
#define maxString 1000
TreeNode* PriorityQueue[maxlength];
int heapSize = 0;

void swap(int i, int j){
	TreeNode* temp = PriorityQueue[i];
	PriorityQueue[i] = PriorityQueue[j];
	PriorityQueue[j] = temp;
}
void min_heapify(int i){
	if(2*i > heapSize) return;
	int left = 2*i;
	int right = 2*i +1;
	int min = i;
	if(PriorityQueue[left]->freq < PriorityQueue[i]->freq){
		min = left;
	}
	if((right <= heapSize) && (PriorityQueue[right]->freq<PriorityQueue[min]->freq)) min = right;
	if(min!= i){
		swap(i,min);
		min_heapify(min);
	}
}

int Minimum(){
	if(heapSize == 0) return -1;
	else return 1;
}

int Extract_Min(){
	if(heapSize == 0) return -1;
	if(heapSize == 1) {
		heapSize -= 1;
		return 1;
	}
	swap(1,heapSize);
	heapSize -= 1;
	min_heapify(1);
	return (heapSize +1);
}

void Heap_change_key(int i, TreeNode* k){
	if(i > heapSize) {
		printf("Node i khong ton tai \n");
		return;
	}
	PriorityQueue[i] = k;
	while((i>1) && (PriorityQueue[i/2]->freq > PriorityQueue[i]->freq)){
		swap(i,i/2);
		i= i/2;
	}
}

void Heap_insert(TreeNode* k){
	if(heapSize == 0){
		PriorityQueue[1] = k;
		heapSize += 1; 
		return;
	}
	heapSize += 1;
	Heap_change_key(heapSize,k);
}

void printPriorityQueue(){
	int i =0;
	for(i =1; i<= heapSize; i++){
		printf("%4c ",PriorityQueue[i]->c);
	}
	printf("\n");
	for(i =1; i<= heapSize; i++){
		printf("%4d ",PriorityQueue[i]->freq);
	}
	printf("\n");
}
/*
	***Huffman
*/
// Build huffman tree
TreeNode* HuffmanTree(){
	while(heapSize > 1){
		TreeNode* temp1 = PriorityQueue[Extract_Min()];
		TreeNode* temp2 = PriorityQueue[Extract_Min()];
		TreeNode* tree = makeNewTreeNode(' ',temp1->freq + temp2->freq);
		tree->left = temp1;
		tree->right = temp2;
		Heap_insert(tree);
	}
	return PriorityQueue[Extract_Min()];
}
int depth(TreeNode* tree){
	if(tree== NULL) return 0;
	int ld = depth(tree->left);
	int rd = depth (tree->right);
	 return 1 +(ld>rd?ld:rd);
}

char* code = NULL;
int index = 0;

void genHuffmanCode(TreeNode* tree)
{
	if(tree == NULL) return;
	if(tree->left == NULL && tree->right == NULL){
		if(strlen(code) != 0) {
			int i =0;
			printf("%c: ",tree->c);
			for(i=0; i< index; i++){
				printf("%c",code[i]);
			}
			printf("\n");
			index --;
		}
		return;
	}
	
	code[index++] = '0';
	genHuffmanCode(tree->left);
	code[index++] = '1';
	genHuffmanCode(tree->right);
	index--;
}

void decode(char* encode, TreeNode* tree){
	TreeNode* temp = tree;
	int i = 0;
	int sz = strlen(encode);
	while(i<sz){
		if(encode[i] == '0') temp = temp->left;		
		if(encode[i] == '1') temp = temp->right;
		if(temp->left == NULL && temp->right == NULL){
			printf("%c",temp->c);
			temp = tree;
		}
		i++;
	}
}


int main(){
	TreeNode* nodeE = makeNewTreeNode('E',125);
	TreeNode* nodeT = makeNewTreeNode('T',93);
	TreeNode* nodeA = makeNewTreeNode('A',80);
	TreeNode* nodeO = makeNewTreeNode('O',76);
	TreeNode* nodeI = makeNewTreeNode('I',72);
	TreeNode* nodeN = makeNewTreeNode('N',71);
	TreeNode* nodeS = makeNewTreeNode('S',65);
	TreeNode* nodeR = makeNewTreeNode('R',61);
	TreeNode* nodeH = makeNewTreeNode('H',55);
	TreeNode* nodeL = makeNewTreeNode('L',41);
	TreeNode* nodeD = makeNewTreeNode('D',40);
	TreeNode* nodeC = makeNewTreeNode('C',31);
	TreeNode* nodeU = makeNewTreeNode('U',27);
	Heap_insert(nodeE);	
	Heap_insert(nodeT);
	Heap_insert(nodeA);
	Heap_insert(nodeO);
	Heap_insert(nodeI);
	Heap_insert(nodeN);
	Heap_insert(nodeS);
	Heap_insert(nodeR);
	Heap_insert(nodeH);
	Heap_insert(nodeL);
	Heap_insert(nodeD);
	Heap_insert(nodeC);
	Heap_insert(nodeU);
	printf("Bang chu cai: \n");
	printPriorityQueue();
	TreeNode* treeHuffman = HuffmanTree();
	code = (char*) malloc((depth(treeHuffman)+1)*sizeof(char));
	if(code == NULL){
		printf("Bo nho day \n");
		exit(1);
	}
	printf("Ma Huffman cua bang chu cai: \n");
	genHuffmanCode(treeHuffman);
	char encode[maxString];
	printf("Nhap vao chuoi can giai ma: \n");
	scanf("%s",encode);
	decode(encode,treeHuffman);
	
	getch();
	return 0;
}
