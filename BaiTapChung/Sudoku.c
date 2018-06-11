#include <stdio.h>
#include <conio.h>
#include <math.h>

int a[9][9] = {
	{0,7,1,0,9,0,8,0,0},
	{0,0,0,3,0,6,0,0,0},
	{4,9,0,0,0,0,7,0,5},
	{0,1,0,9,0,0,0,0,0},
	{9,0,2,0,0,0,6,0,3},
	{0,0,0,0,0,8,0,2,0},
	{8,0,5,0,0,0,0,7,6},
	{0,0,0,6,0,7,0,0,0},
	{0,0,7,0,4,0,3,5,0},
};
int solution[9][9] = {
	{ 0, 7, 1, 0, 9, 0, 8, 0, 0 },
	{ 0, 0, 0, 3, 0, 6, 0, 0, 0 },
	{ 4, 9, 0, 0, 0, 0, 7, 0, 5 },
	{ 0, 1, 0, 9, 0, 0, 0, 0, 0 },
	{ 9, 0, 2, 0, 0, 0, 6, 0, 3 },
	{ 0, 0, 0, 0, 0, 8, 0, 2, 0 },
	{ 8, 0, 5, 0, 0, 0, 0, 7, 6 },
	{ 0, 0, 0, 6, 0, 7, 0, 0, 0 },
	{ 0, 0, 7, 0, 4, 0, 3, 5, 0 },
};

int n = 9;

void GhiNhan(){
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			printf("%d ", solution[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int Ucv(int b, int k){
	int x = k / n;
	int y = k%n;
	//if (a[x][y] != 0) return 0;
	for (int i = 0; i<n; i++){
		if (b == solution[x][i]) return 0;
	}
	for (int i = 0; i<n; i++){
		if (b == solution[i][y]) return 0;
	}
	int m = sqrt((double)n);
	int p = x / m;
	int q = y / m;

	for (int i = p*m; i<(p + 1)*m; i++){
		for (int j = q*m; j<(q + 1)*m; j++){
			if (i == x && j == y) continue;
			if (solution[i][j] == b) return 0;
		}
	}
	return 1;
}

int canSol = 0;

void soduku(int k){
	int x = k / n;
	int y = k%n;
	if (k == n*n){
		GhiNhan();
		canSol = 1;
	}
	else if (a[x][y] != 0) {
		soduku(k + 1);
	}else
	{
		for (int i = 1; i <= n; i++){
			if (Ucv(i, k) == 1){
				solution[x][y] = i;
				if (k == n*n - 1) {
					GhiNhan();
					canSol = 1;
					//_getch();
				}
				else soduku(k + 1);
			}
		}
	}
	solution[x][y] = a[x][y];
}



int main(){

	soduku(0);
	if (canSol==0){
		printf("Can't solve this sodoku game !!!. \n");
	}

	_getch();
	return 0;
}
