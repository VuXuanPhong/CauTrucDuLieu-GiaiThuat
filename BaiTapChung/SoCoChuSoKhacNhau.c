#include <stdio.h>
#include <conio.h>

int numbers[6];

int Ucv(int i, int k, int n){
	if (k == n - 1){
		if (i == 0) return 0;
	}
	for (int j = 0; j < k; j++){
		if (numbers[j] == i) return 0;
	}
	return 1;
}

void GhiNhan(int n){
	for (int i = n-1; i >= 0; i--){
		printf("%d", numbers[i]);
	}
	printf("\n");
}

void sol(int k, int n){
	for (int i = 0; i <= 9; i++){
		if (Ucv(i, k,n)==1){
			numbers[k] = i;
			if (k == n - 1){
				GhiNhan(n);
			}
			else
			{
				sol(k + 1, n);
			}
		}
	}
}


int main(){
	for (int k = 2; k <= 6; k++){
		sol(0, 2);
	}
	_getch();
	return 0;
}