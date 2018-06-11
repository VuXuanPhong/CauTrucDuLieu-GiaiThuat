#include <stdio.h>
#include <conio.h>


int* giaiThua = NULL;
int szMax = 100;
int soChuSo = 1;

void tinhGiaiThua(int n){
    int j = soChuSo - 1;
    int r = 0;
    for(int i =3; i<=n; i++){
        for(int k =0; k <= j; k ++){
            int nhan = giaiThua[k]*i + r;
            r = nhan/10;
            giaiThua[k] = nhan%10;
        }
        while(r!=0){
            j =j +1;
            if(j>=szMax){
                szMax *= 2;
                giaiThua = (int*) malloc(szMax*sizeof(int));
                if(giaiThua == NULL){
                    printf("Bo nho khong du \n");
                    exit(0);
                }
            }
            int a = r%10;
            r = r/10;
            giaiThua[j] = a;
        }
    }

    for(int i=j; i>=0; i--){
        printf("%d",giaiThua[i]);
    }

}

int main(){
    giaiThua = (int*) malloc(szMax*sizeof(int));
    if(giaiThua == NULL) {
        printf("Bo nho khong du \n");
        return 0;
    }
    giaiThua[0] = 2;

    tinhGiaiThua(20);
    getch();
    return 0;
}
