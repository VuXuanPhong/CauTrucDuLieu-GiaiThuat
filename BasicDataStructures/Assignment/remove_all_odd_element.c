/*************************SOLVE DATA STRUCTURES PROBLEM*******************************
When            Who         What
30/04/2018      Phong      Assignment Basic Data Structures

*************************************************************************************/

/*
** Description:
	Remove all odd element from link list... 
*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
	int inf;
	struct Node* next;
	
};

typedef struct Node LIST;

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

void display(LIST* lst){
	LIST* t = lst;
	while(t!= NULL){
		printf("%d ",t->inf);
		t = t->next;		
	}
	printf("\n");
}

LIST* removeAllOddElement(LIST* lst){
	if(lst == NULL) return NULL;
	while(lst!=NULL && !(lst->inf&1)){
		LIST* t = lst;
		lst = t->next;
		t->next = NULL;
		free(t);
	}
	if(!lst) return NULL;
	LIST* t = lst;
	while(t->next!= NULL){
		if(!(t->next->inf&1)){
			LIST* t1 = t->next;
			while(!(t1->inf&1)){
				LIST* t2 = t1;
				t1 = t1->next;
				t2->next = NULL;
				free(t2);
				if(t1 == NULL) break;
			}
			t->next = t1;
		}
		t = t->next;
		if(t == NULL) break;
	}
	return lst;
}


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
	lst = removeAllOddElement(lst);
	display(lst);
	return 0;
}
