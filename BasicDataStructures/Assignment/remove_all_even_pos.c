/*************************SOLVE DATA STRUCTURES PROBLEM*******************************
When            Who         What
29/04/2018      Phong      Assignment Basic Data Structures

*************************************************************************************/

/*
** Description:
	Remove all element at positive even in link list. Start by one.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
	int inf;
	struct Node* next;
};

typedef struct Node LIST;

LIST* makeNewNode(int d);
LIST* insertToHead(LIST* lst, int d);
LIST* OddList(LIST* Linp);
void display(LIST* list);


int main(){
	LIST* lst = NULL;
	lst = insertToHead(lst,10);
	lst = insertToHead(lst,5);
	lst = insertToHead(lst,6);
	lst = insertToHead(lst,3);
	lst = insertToHead(lst,4);
	lst = insertToHead(lst,2);
	lst = insertToHead(lst,1);
	lst = insertToHead(lst,8);
	lst = insertToHead(lst,9);
	lst = insertToHead(lst,7);
	display(lst);
	lst = OddList(lst);
	display(lst);
	return 0;
}

LIST* makeNewNode(int d){
	LIST* temp = NULL;
	temp = (LIST*) malloc(sizeof(LIST));
	if(!temp){
		printf("Not enough memory. \n");
		exit(0);
	}
	temp->inf = d;
	temp->next = NULL;
	return temp;
}

LIST* insertToHead(LIST* lst, int d){
	LIST* t = makeNewNode(d);
	t->next = lst;
	lst = t;
	return lst;
}

LIST* OddList(LIST* Linp){
	LIST* temp = NULL;
	temp = (LIST*) malloc(sizeof(LIST));
	if(temp == NULL) exit(0);
	temp->next = NULL;
	LIST* lst = temp;
	LIST* t = Linp;
	int i = 1;
	while(t!= NULL){
		if(!(i&1)){
			temp->inf = t->inf;
			if(t->next == NULL || t->next->next == NULL) break;
			temp->next = (LIST*) malloc(sizeof(LIST));
			if(temp->next==NULL) exit(0);
			temp->next->next = NULL;
			temp = temp->next;
		}
		t = t->next;
		i++;
	}
	return lst;
}

void display(LIST* lst){
	LIST* t = lst;
	while(t!= NULL){
		printf("%d ",t->inf);
		t = t->next;		
	}
	printf("\n");
}

