 #include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int* A = NULL;
int n = 1000000;

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void initArr(int sz){
    A = (int*) malloc(sz*sizeof(int));
    if(A==NULL){
        printf("Khong du bo nho \n");
        exit(0);
    }
    srand(time(NULL));
    for(int i=0; i<sz; i++){
        A[i] = rand();
    }
}

void printArr(int n){
    for(int i=0; i< n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void BubbleSort(int sz){
    for(int i=0; i< sz-1; i++){
        for(int j=i; j< sz; j++){
            if(A[i] > A[j]){
                swap(&A[i],&A[j]);
            }
        }
    }
}

void SelectionSort(int sz){
    for(int i=0;i< sz - 1; i++){
        int indexMinimum = i;
        for(int j = i+1; j<sz; j++){
            if(A[j] < A[indexMinimum]){
                indexMinimum = j;
            }
        }
        if(indexMinimum!= i){
            swap(&A[i],&A[indexMinimum]);
        }
    }
}

void InsertSort(int* A, int left, int right){
    for(int i=left; i<= right; i++){
        int X = A[i];
        int j = i -1;
        for(j =i -1; j> -1; j --){
            if(A[j] > X) A[j+1] = A[j];
            else break;
        }
        A[j+1] = X;
    }

}


int main(){
    initArr(n);
    printArr(n);
    //BubbleSort(n);
    //SelectionSort(n);
    InsertSort(n);
    printArr(n);
    getch();
    return 0;
}
