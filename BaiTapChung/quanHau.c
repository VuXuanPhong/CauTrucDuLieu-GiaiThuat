#include <stdio.h>
#include <conio.h>

int n = 8;
int a[8];

int Ucv(int i, int k){
    for(int j =0; j < k;j++){
        if((a[j] == i)|| (abs(a[j]-i)==abs(j-k))) return 0;
    }
    return 1;
}
int count = 0;
void Ghinhan(){
    count++;
    printf("%d: ",count);
    for(int i =0; i< n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
void xepHau(int k){
    for(int i=0;i<n;i++){
        if(Ucv(i,k)){
            a[k] = i;
            if(k==n-1) Ghinhan();
            else xepHau(k+1);
        }
    }
}

int main(){
    xepHau(0);


    getch();
    return 0;
}
