/*************************SOLVE TREE PROBLEM****************************************
When            Who         What
15/04/2018      Phong      Cau truc du leu Heap

*************************************************************************************/
/* Cac phep toan co ban
	+ Bo sung va loai bo node
	+ Khoi phuc tinh chat Heap (maxHeap or minHeap).
	+ Tao maxHeap or minHeap tu mot mang khong duoc sap xep: Build-Max-Heap.
	** Cau truc Heap duoc cai dat bang mang **
	** Tinh chat: 
		+ Doi voi maxHeap: parent(i) >= i. Node root la node co gia tri lon nhat
		+ Doi voi minHeap: parent(i) <= i. Node root la node co gia tri nho nhat
		+ A[2*i] la con trai cua i, A[2*i+1] la con phai cua i.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int* Heap = NULL;
int size = 10;

int* inputRandom(int* Heap, int size){
	int i = 0;
	for(i =1; i< size; i++){
		printf("Nhap vap phan tu thu %d: ", i);
		scanf("%d",&Heap[i]);
	}
}

void output(int* Heap, int size){
	int i =1;
	for( i=1; i< size; i++){
		printf("%d ",Heap[i]);
	}
	printf("\n");
}


void swap(int* A, int i, int j){
	int a = A[i];
	A[i] = A[j];
	A[j] =  a;
}

void max_heapify(int* A, int i, int n){ // khoi phuc lai tinh chat maxHeap
	if(i>n) return;
	int left = 2*i;
	int right = 2*i + 1;
	int largest = i;
	if((left <= n-1) && (A[left] > A[i])){
		largest = left;
	}
	if((right <= n-1) && (A[right] > A[largest])){
		largest = right;
	}
	if(largest != i){
		swap(A,i,largest);
		max_heapify(A,largest,n);
	}
	
}

void build_maxheapi(int* A, int sz){
	int i =0;
	for( i =sz/2; i>= 1; i--){
		max_heapify(A,i,sz);
		//output(A,sz);
	}
}

void min_heapify(int* A, int i, int n){
	int left = 2*i;
	int right = 2*i +1;
	int minimum = i;
	if((left <= n-1) && (A[left] < A[i])) minimum = left;
	if((right <= n-1)&&(A[right] < A[minimum])) minimum = right;
	if(minimum != i){
		swap(A,i,minimum);
		min_heapify(A,minimum,n);
	}
}

void build_minheapi(int* A, int sz){
	int i =0;
	for( i =sz/2; i>= 1; i--){
		min_heapify(A,i,sz);
		//output(A,sz);
	}
}


int main(){
	printf("Nhap vao size cho Heap: ");
	scanf("%d",&size);
	
	Heap = (int*) malloc(sizeof(int)*(size+1));
	if(Heap == NULL){
		printf("Bo nho day \n");
		exit(1);
	}
	
	inputRandom(Heap,size +1);
	output(Heap,size+1);
	build_minheapi(Heap,size+1);
	output(Heap,size+1);
	
	getch();
	return 0;
}
