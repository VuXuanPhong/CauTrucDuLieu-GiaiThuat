#include <stdio.h>
#include <conio.h>

int n;
int a[] = {1,2,3};
int m[3];

int Ucv(int i, int k){
    for(int j = 0; j < k; j++){
        if(m[j]==a[i]) return 0;
    }
    return 1;
}
void Ghinhan(){
    for(int i = 0; i< n; i++){
        printf("%d ", m[i]);
    }
    printf("\n");
}

void hienthihoanvi(int k){
    for(int i = 0; i <n; i++){
        if(Ucv(i,k)==1){
            m[k] = a[i];
            if(k==n-1) Ghinhan();
            else hienthihoanvi(k+1);
        }
    }
}

int main(){
    n = 3;

    hienthihoanvi(0);

    getch();
    return 0;
}
