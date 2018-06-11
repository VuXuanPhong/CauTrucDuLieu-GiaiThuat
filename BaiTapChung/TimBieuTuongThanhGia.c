#include <stdio.h>
#include <conio.h>

int chuThap[12][12] = { 
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0 },
	{ 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0 },
	{ 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
	{ 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
	{ 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0 },
	{ 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
};


int toaDo;
int x = 1;

int n = 12;

void GhiNhan(){
	int row = toaDo / n;
	int col = toaDo % n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			chuThap[i][j] = 0;
		}
	}
	chuThap[row][col] = 1;
	int a = row;
	int b = col;
	for (int j = -x; j <= x; j++){
		a += j;
		chuThap[a][b] = 1; 
		a = row;
	}
	a = row;
	for (int j = -x; j <= x; j++){
		b += j;
		chuThap[a][b] = 1;
		b = col;
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			printf("%d", chuThap[i][j]);
		}
		printf("\n");
	}
}

int Ucv(int k, int* x){
	int row = k / n;
	int col = k % n;

	int a = row;
	int b = col;

	for (int j = -*x; j < *x; j++){
		a += j;
		if (a < 0 || a >= n) return 0;
		if (chuThap[a][b] != 1) return 0;
		a = row;
	}
	a = row;
	for (int j = -*x; j < *x; j++){
		b += j;
		
		if (a < 0 || a >= n) return 0;
		if (chuThap[a][b] != 1) return 0;
		b = col;
	}
	b = col;
	int m = *x + 1;
	if (Ucv(k, &m) == 1){
		*x = m;
	}
	return true;
}

void solution(){
	for (int i = 0; i < n*n; i++){
		if (Ucv(i, &x) == 1){
			toaDo = i;
			//x++;
		}
	}
}

int main(){
	solution();
	GhiNhan();

	_getch();
	return 0;
}
