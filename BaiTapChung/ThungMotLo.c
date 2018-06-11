#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int** BanCo = NULL;
int n = 8;

void init(int x, int y){
	BanCo = (int**)malloc(n * sizeof(int*));
	if (BanCo == NULL){
		printf("Bo nho khong du \n");
		exit(0);
	}
	for (int i = 0; i < n; i++){
		BanCo[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (j == x && i == y){
				BanCo[i][j] = -1;
			}
			else BanCo[i][j] = 0;
		}
	}
}

void printBanCo(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			printf("%d  ", BanCo[i][j]);
		}
		printf("\n");
	}
}

int viTriLo(int x, int y, int p, int r){
	int a = (r + p) / 2;
	if (x <=a && y <= a) return -1;
	if (x > a && y <= a) return 1;
	if (x <=a && y > a)	 return -2;
	if (x > a && y > a)	 return 2;
}
int L = 1;
void solution(int x, int y, int px, int rx, int py, int ry){
	if (rx - px + 1 == 2){
		for (int i = py; i <= ry; i++){
			for (int j = px; j <= rx; j++){
				if (BanCo[i][j] == 0){
					BanCo[i][j] = L;
				}
			}
		}
		L++;
	}
	else{
		int ax = (rx + px) / 2;
		int by = (ry + py) / 2;
		if (x <= ax && y <= by){
			BanCo[by + 1][ax] = L;
			L++;
			BanCo[by][ax + 1] = L;
			L++;
			BanCo[by + 1][ax+1] = L;
			L++;
			solution(x, y, px, ax, py, by);
			solution(ax+1, by + 1, ax+1, rx, by + 1, ry);
			solution(ax, by + 1, px, ax, by + 1, ry);
			solution(ax + 1, by, ax + 1, rx, py, by);
		}
		if (x > ax && y <= by){

			BanCo[by][ax] = L;
			L++;
			BanCo[by+1][ax] = L;
			L++;
			BanCo[by + 1][ax + 1] = L;
			L++;
			solution(x, y, ax + 1, rx, py, by);
			solution(ax, by, px, ax, py, by);
			solution(ax, by + 1, px, ax, by + 1, ry);
			solution(ax + 1, by + 1, ax + 1, rx, by + 1, ry);
		}
		if (x <= ax && y > by){
			BanCo[by][ax] = L;
			L++;
			BanCo[by][ax + 1] = L;
			L++;
			BanCo[by + 1][ax + 1] = L;
			L++;
			solution(x, y, px, ax, by + 1, ry);
			solution(ax + 1, by, ax + 1, rx, py, by);
			solution(ax, by, px, ax, py, by);
			solution(ax + 1, by + 1, ax + 1, rx, by + 1, ry);
		}
		if (x > ax && y > by){

			BanCo[by + 1][ax] = L;
			L++;
			BanCo[by][ax + 1] = L;
			L++;
			BanCo[by][ax] = L;
			L++;
			solution(ax, by + 1, px, ax, by + 1, ry);
			solution(ax + 1, by, ax + 1, rx, py, by);
			solution(x, y, ax + 1, rx, by + 1, ry);
			solution(ax, by, px, ax, py, by);
		}
	}
	printBanCo();
	printf("\n");
}



int main(){
	int x,y;
	printf("Nhap vao vi tri bi thung: \n");
	printf("Theo x: "); scanf_s("%d", &x);
	printf("Theo y: "); scanf_s("%d", &y);
	init(x,y);
	printBanCo();
	printf("Loi giai: \n");
	solution(x, y, 0, n-1, 0, n-1);
	_getch();
	return 0;
}