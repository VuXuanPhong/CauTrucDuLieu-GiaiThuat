/*************************SOLVE TREE PROBLEM****************************************
When            Who         What
15/04/2018      Phong      Bieu dien Binary tree su dung mang

*************************************************************************************/

#include <stdio.h>
#include <conio.h>

#define n 11

char left_child(int i , char* A){ // con trai cua nut thu i la A[2*i]
	if(2*i <= n && A!= NULL)
		return A[2*i];
}

char right_child(int i, char* A){ // con phai cua nut thu i la A[2*i+1]
	if(2*i +1 <= n && A!= NULL)
		return A[2*i+1];
}

char parent(int i, char* A){ // cha cua nut thu i la A[i/2]
	if(i>1 && A!= NULL)
		return A[i/2];
	return NULL;
}

char root(char* A){
	if(A!= NULL) return A[1];
}

int isLeaf(int i, char* A){
	return (2*i > n);
}

int main(){
	char A[n];
	A[1] = 'H';
	A[2] = 'D';
	A[3] = 'K';
	A[4] = 'B';
	A[5] = 'F';
	A[6] = 'J';
	A[7] = 'L';
	A[8] = 'A';
	A[9] = 'C';
	A[10] = 'E';
	
	char c = left_child(2,A);
	printf("%c",c);
	
	getch();
	return 0;
}


