#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int* A = NULL;
int n = 10000;

void ShellSort(int* A, int n){
    int k = n/2;
    while(k!=0){
		int m =0;
        for(m=0; m < k; m++){
			int i = 0;
            for( i =k + m; i < n; i = i+ k){
                int X = A[i];
                int j = i -k;
                for(j = i -k; j > -1; j = j-k){
                    if(A[j] > X) A[j+k] = A[j];
                    else break;
                }
                A[j+k] =  X;
            }

        }


        k = k/2;
    }

}
void initArr(int sz){
    A = (int*) malloc(sz*sizeof(int));
    if(A==NULL){
        printf("Khong du bo nho \n");
        exit(0);
    }
    srand(time(NULL));
    int i =0;
	for(i=0; i<sz; i++){
        A[i] = rand()% 100000000000;
    }
}

void printArr(int n){
    int i =0;
	for(i=0; i< n; i++){
        printf("%d \n", A[i]);
    }
    printf("\n");
}

int main(){
    initArr(n);
    //printArr(n);
    ShellSort(A,n);
    printArr(n);
    //printf("Hello \n");
    getch();
    return 0;
}
