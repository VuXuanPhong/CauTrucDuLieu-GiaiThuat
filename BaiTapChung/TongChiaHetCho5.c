#include <stdio.h>
#include <conio.h>

int a[3];

int Ucv(int i, int k){
    if(k < 2) return 1;
    int Sum = 0;
    for(int i =0 ; i <= k-1; i++){
        Sum += a[i];
    }
    Sum += i;
    if(Sum%5==0) return 1;
    else return 0;
}

void GhiNhan(){
    for(int i =0 ; i <3; i++){
        printf("%d",a[i]);
    }
    printf("\n");
}

void hienThiSoCoTongChiaHetCho5(int k){
    for(int i=0; i <=9; i++){
        if(Ucv(i,k)==1){
            a[k] = i;
            if(k==2) GhiNhan();
            else hienThiSoCoTongChiaHetCho5(k+1);
        }
    }

}

int main(){

    hienThiSoCoTongChiaHetCho5(0);


    getch();
    return 0;
}
