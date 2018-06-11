#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int n = 100;
int* a = NULL;

void init(int n){
	a = (int*)malloc(n*sizeof(int));
	if (a == NULL) {
		printf("Bo nho khong du \n");
		exit(1);
	}
	srand(time(NULL));
	int i =0;
	for (i = 0; i < n; i++){
		a[i] = rand();
	}
}

void swap(int* x, int* y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void max_heapify(int* A, int i, int n){
	if (i < 0) return;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest = i;
	if ((left <= n - 1) && (A[left] > A[i])) largest = left;
	if ((right <= n - 1) && (A[right] > A[largest])) largest = right;

	if (largest != i) {
		swap(&A[i], &A[largest]);
		max_heapify(A, largest, n);
	}

	max_heapify(A, i - 1, n);
}

void HeapSort(int* A, int n){
	int i =0;
	for ( i = n-1; i >= 1; i--){
		swap(&A[0], &A[i]);
		max_heapify(A, (i -1)/ 2, i );
	}
}

void printArray(int n){
	int i =0;
	for (i = 0; i < n; i++){
		printf("%d \n", a[i]);
	}
	printf("\n");
}

int main(){
	printf("Nhap vap so luong phan tu: ");
	scanf("%d",&n);
	init(n);
	printf("Mang truoc khi sap xep: \n");
	printArray(n);
	max_heapify(a, (n - 1) / 2, n);
	HeapSort(a, n);
	printf("Sau khi sap xep: \n");
	printArray(n);
	getch();
	return 0;
}
