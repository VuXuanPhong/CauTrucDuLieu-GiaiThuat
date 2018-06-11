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
	int i = 0;
	for (i = 0; i < n; i++){
		a[i] = rand();
	}
}

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int findPivot(int* A, int left, int right){
	int midle = (left + right) / 2;
	int a[3];
	a[0] = A[left];
	a[1] = A[midle];
	a[2] = A[right];

	int i =0;
	int j = 0;
	for ( i = 0; i < 2; i++){
		for ( j = i+1; j < 3; j++){
			if (a[i] > a[j]){
				swap(&a[i], &a[j]);
			}
		}
	}

	if (A[left] == a[1]) return left;
	else if (A[right] == a[1]) return right;
	else return midle;
}

int part(int* A, int left, int right, int x){
	int i = left, j = right;
	while (i<=j)
	{
		while (A[i] < x) i++;
		while (A[j] > x) j--;
		if (i <= j) {
			swap(&A[i], &A[j]);
			i++;
			j--;
		}
	}
	return i;
}


void InsertSort(int* A, int left, int right){
    int i = 0;
	for(i=left; i<= right; i++){
        int X = A[i]; 
        int j = i -1;
        for(j =i -1; j> -1; j --){
            if(A[j] > X) A[j+1] = A[j];
            else break;
        }
        A[j+1] = X;
    }

}

void quickSort(int* A, int left, int right){
	if (right - left == 0) return;
	if (right - left == 1){
		if (A[left] > A[right]) swap(&A[left], &A[right]);
		return;
	}
	if(right - left + 1 <= 9){
		InsertSort(A,left,right);
		return;
	} 
	if (left < right){
		int pivot = findPivot(A, left, right);
		int x = A[pivot];
		swap(&A[pivot], &A[right]);
		int k = part(A, left, right-1, x);
		swap(&A[k], &A[right]);

		quickSort(A, left, k - 1);
		quickSort(A, k+1, right);
	}
}

void printArray(int n){
	int i = 0;
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
	printf("Sau khi sap xep: \n");
	quickSort(a, 0, n-1);
	printArray(n);
	getch();
	return 0;
}
