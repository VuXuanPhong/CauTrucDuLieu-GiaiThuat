#include <stdio.h>
#include <conio.h>

char a[6];
int n;

void Ghinhan(){
    for(int i = 0; i< n; i++){
        printf("%c ", a[i]);
    }
    printf("\n");
}



int Ucv(char c, int k){
    int t = 0;
    for(int i = 0; i < k; i++){
        if(a[i] == '(') t++;
        else t--;
        if(t <0) return 0;
    }
    if(c=='(') t++;
    else t--;
    if(k < n-1){
        if(t < 0) return 0;
        else return 1;
    }
    else if(k==n-1){
        if(t!=0) return 0;
        else return 1;
    }
}

void hienThiChuoi(int k){
    if(Ucv('(',k)==1){
        a[k] = '(';
        if(k == n-1) Ghinhan();
        else hienThiChuoi(k+1);
    }
    if(Ucv(')',k)==1){
        a[k] = ')';
        if(k == n-1) Ghinhan();
        else hienThiChuoi(k+1);
    }
}

int main(){
    n = 6;
    hienThiChuoi(0);
    getch();
    return 0;
}
