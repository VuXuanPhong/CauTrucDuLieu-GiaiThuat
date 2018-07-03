/*************************SOLVE DATA STRUCTURES PROBLEM*******************************
When            Who         What
29/04/2018      Phong      Assignment Basic Data Structures

*************************************************************************************/

/*
** Description:
	Bai tap trang 138, sach Cau truc du lieu va giai thuat- Thay Nguyen Duc Nghia.
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct _studentNode
{
	char* name;
	struct _studentNode* next;
};
typedef struct _studentNode StudentNode;

struct _classNode
{
	char* name;
	struct _classNode* next;
	StudentNode* students;
};

typedef struct _classNode ClassNode;


StudentNode* makeNewStudent(char* name){
	StudentNode* newNode = NULL;
	newNode = (StudentNode*)malloc(sizeof(StudentNode));
	if (newNode == NULL){
		printf("Bo nho day \n");
		exit(0);
	}
	newNode->name = name;
	newNode->next = NULL;
	return newNode;
}

StudentNode* initListSv(StudentNode* list, char* name){
	if (list == NULL){
		list = makeNewStudent(name);
	}
	else
	{
		StudentNode* temp = list;
		while (temp->next!= NULL)
		{
			temp = temp->next;
		}
		temp->next = makeNewStudent(name);
	}
	return list;
}

ClassNode* initBKHN(){
	ClassNode* bkhn = NULL;

	ClassNode* K51 = NULL;
	K51 = (ClassNode*)malloc(sizeof(ClassNode));
	if (K51 == NULL){
		printf("Bo nho day \n");
		exit(0);
	}
	StudentNode* svK51 = NULL;
	svK51 = initListSv(svK51, "An");
	svK51 = initListSv(svK51, "Anh");
	svK51 = initListSv(svK51, "Ban");
	svK51 = initListSv(svK51, "Ba");
	K51->name = "K51";
	K51->students = svK51;
	K51->next = NULL;

	ClassNode* K49 = NULL;
	K49 = (ClassNode*)malloc(sizeof(ClassNode));
	if (K49 == NULL){
		printf("Bo nho day \n");
		exit(0);
	}
	StudentNode* svK49 = NULL;
	svK49 = initListSv(svK49, "Hoa");
	svK49 = initListSv(svK49, "Lan");
	svK49 = initListSv(svK49, "Mai");
	svK49 = initListSv(svK49, "Mi");
	svK49 = initListSv(svK49, "Hoan");
	K49->name = "K49";
	K49->students = svK49;
	K49->next = NULL;
	K51->next = K49;

	ClassNode* K52 = NULL;
	K52 = (ClassNode*)malloc(sizeof(ClassNode));
	if (K52 == NULL){
		printf("Bo nho day \n");
		exit(0);
	}
	StudentNode* svK52 = NULL;
	svK52 = initListSv(svK52, "La");
	svK52 = initListSv(svK52, "Phong");
	svK52 = initListSv(svK52, "Ga");
	svK52 = initListSv(svK52, "Phong");
	K52->name = "K52";
	K52->students = svK52;
	K52->next = NULL;
	K49->next = K52;


	ClassNode* K50 = NULL;
	K50 = (ClassNode*)malloc(sizeof(ClassNode));
	if (K50 == NULL){
		printf("Bo nho day \n");
		exit(0);
	}
	StudentNode* svK50 = NULL;
	svK50 = initListSv(svK50, "Quang");
	svK50 = initListSv(svK50, "Phan");
	svK50 = initListSv(svK50, "Van");
	svK50 = initListSv(svK50, "Chanh");
	K50->name = "K50";
	K50->students = svK50;
	K50->next = NULL;
	K52->next = K50;

	ClassNode* K53 = NULL;
	K53 = (ClassNode*)malloc(sizeof(ClassNode));
	if (K53 == NULL){
		printf("Bo nho day \n");
		exit(0);
	}
	StudentNode* svK53 = NULL;
	svK53 = initListSv(svK53, "Nam");
	svK53 = initListSv(svK53, "Ngoan");
	svK53 = initListSv(svK53, "Chu");
	svK53 = initListSv(svK53, "Lan");
	K53->name = "K53";
	K53->students = svK50;
	K53->next = NULL;
	K50->next = K53;

	bkhn = K51;
	return bkhn;
}

int numStudents1(ClassNode* ClPoint){
	StudentNode* listStudent = ClPoint->students;
	int i = 0;
	while (listStudent!= NULL)
	{	
		i++;
		listStudent = listStudent->next;
	}
	return i;
}

int numStudents2(ClassNode* list, char* className){
	ClassNode* temp = list;
	StudentNode* listSv = NULL;

	while (temp!= NULL)
	{
		//if (temp == NULL) break;
		if (strcmp(temp->name,className) == 0){
			listSv = temp->students;
			break;
		}
		temp = temp->next;
	}
	if (listSv == NULL) return -1;
	int i = 0;
	while (listSv != NULL)
	{
		i++;
		listSv = listSv->next;
	}

	return i;
}

int main(){

	ClassNode* bkhn = initBKHN();

	int d = numStudents1(bkhn->next->next);
	printf("So luong sinh vien cua lop %s la %d \n",bkhn->next->next->name, d);

	int c = numStudents2(bkhn, "K48");
	if (c != -1){
		printf("So luong sinh vien cua lop la %d", c);
	}
	else{
		printf("Khong ton tai lop nay trong danh sach \n");
	}
	getch();
	return 0;
}
