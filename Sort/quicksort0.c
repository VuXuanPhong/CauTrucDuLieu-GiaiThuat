#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int n = 10000;

int* init(){
	int* A = NULL;
	A = (int*) malloc(n*sizeof(int));
	if(A == NULL){
		printf("Bo nho day\n");
		exit(1);
	}
	int i =0;
	for(i =0; i<n; i++){
		A[i] = rand()%1000;
	}
	return A;
}
void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


int findPivot(int* A, int left, int right){
	int midle = (left+right)/2;
	int b[3];
	b[0] = A[left];
	b[1] = A[midle];
	b[2] = A[right];
	int i =0, j;
	for(i=0; i<2; i++){
		
		for( j = i+1; j<3; j++){
			if(b[i] > b[j]){
				int temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}
	if(b[1] == A[left]) return left;
	if(b[1] == A[right]) return right;
	return midle;
}

int partition(int* A, int left, int right, int x){
	int i = left;
	int j = right;
	while(i<=j){
		while( x > A[i]) i++;
		while( x < A[j]) j--;
		if(i <= j){
			swap(&A[i],&A[j]);
			i++;
			j--;
		}
	}
	return i;
}

void quickSort(int* A, int left, int right){
	if(right-left == 0) return;
	if(right - left == 1){
		if(A[left] > A[right]) swap(&A[left],&A[right]);
	}
	if(left < right){
		int pivot = findPivot(A,left, right);
		int x = A[pivot];
		swap(&A[pivot],&A[right]);
		int j = partition(A,left,right-1,x);
		swap(&A[j],&A[right]);
		
		quickSort(A,left,j-1);
		quickSort(A,j+1,right);
	}
}

void printArr(int* A){
	int i =0;
	for(i = 0; i< n; i++){
		printf("%d \n",A[i]);
	}
	printf("\n");
}

int main(){
	int* A = init();
	printArr(A);
	quickSort(A,0,n-1);
	printArr(A);
	getch();
	return 0;
}

