#include <stdio.h>
#include <conio.h>
/*************************SOLVE TREE PROBLEM****************************************
When            Who         What
29/04/2018      Phong      Basic Data Structures priority_queue

*************************************************************************************/
/*
** Mo ta:
	Priority Queue use Heap. 
	Heap is a Data structures base binary tree (use array)
	Priority Queue in this file is sorted by increasing.
*/
#define maxLength 1000
int PriorityQueue[maxLength];
int heapSize = 0;

// cac thap tac co ban
void swap(int i, int j){
	int temp = PriorityQueue[i];
	PriorityQueue[i] = PriorityQueue[j];
	PriorityQueue[j] = temp;
}
void min_heapify(int i){
	if(2*i > heapSize) return;
	int left = 2*i;
	int right = 2*i +1;
	int min = i;
	if(PriorityQueue[left] < PriorityQueue[i]){
		min = left;
	}
	if((right <= heapSize) && (PriorityQueue[right]<PriorityQueue[min])) min = right;
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

void Heap_change_key(int i, int k){
	if(i > heapSize) {
		printf("Node i khong ton tai \n");
		return;
	}
	PriorityQueue[i] = k;
	while((i>1) && (PriorityQueue[i/2] > PriorityQueue[i])){
		swap(i,i/2);
		i= i/2;
	}
}

void Heap_insert(int k){
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
		printf("%d ",PriorityQueue[i]);
	}
	printf("\n");
}

int main(){
	Heap_insert(5);
	Heap_insert(2);	
	Heap_insert(1);
	Heap_insert(0);	
	Heap_insert(3);
	Heap_insert(6);
	printf("Cac phan tu cua hang doi co thu tu la: \n");
	printPriorityQueue();
	int indexMin = Extract_Min(); 
	printf("Phan tu nho nhat la: %d \n", PriorityQueue[indexMin]);
	printf("Cac phan tu cua hang doi co thu tu sau khi lay ra phan tu nho nhat la: \n");
	printPriorityQueue();
	getch();
	return 0;
}
