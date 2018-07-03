/*************************SOLVE DATA STRUCTURES PROBLEM*******************************
When            Who         What
29/04/2018      Phong      Basic Data Structures double link list

*************************************************************************************/

/*
** Description:
	Single link list and methods...
*/
#include <stdio.h>
#include <stdlib.h>

typedef int data;

struct _node{
	data d;
	struct _node* pNext;
	struct _node* pPre;
};

typedef struct _node Node;

struct _doubleList{
	Node* pHead;
	Node* pTail;
	int size;
};

typedef struct _doubleList DoubleList;

// method:
Node* makeNewNode(data d);
DoubleList* init();
void insertToHead(DoubleList* list, data d);
void insertToTail(DoubleList* list, data d);
void insertAfterKth(DoubleList* list, data d, int k);
void changeValueKth(DoubleList* list, data d, int k); 
void removeHead(DoubleList* list);
void removeTail(DoubleList* list);
void removeElementKth(DoubleList* list, int k);
void removeAllValueK(DoubleList* list, int k);
void printListFromHead(DoubleList* list);
void printListFromTail(DoubleList* list);

int main(){
	DoubleList* lst = init();
	insertToHead(lst,5);
	insertToHead(lst,6);
	insertToHead(lst,3);
	insertToTail(lst,1);
	insertToTail(lst,2);
	insertAfterKth(lst,4,1);
	printListFromHead(lst);
	removeHead(lst);
	printListFromHead(lst);
	removeHead(lst);
	printListFromHead(lst);
	removeHead(lst);
	printListFromHead(lst);
	removeHead(lst);
	printListFromHead(lst);
	removeHead(lst);
	printListFromHead(lst);
	removeHead(lst);
	printListFromHead(lst);
	
	insertToHead(lst,5);
	insertToHead(lst,6);
	insertToHead(lst,3);
	insertToTail(lst,1);
	insertToTail(lst,2);
	insertAfterKth(lst,4,1);
	printListFromHead(lst);
	removeTail(lst);
	printListFromHead(lst);
	removeTail(lst);
	printListFromTail(lst);
	removeTail(lst);
	printListFromTail(lst);
	removeTail(lst);
	printListFromTail(lst);
	removeTail(lst);
	printListFromTail(lst);
	removeTail(lst);
	printListFromTail(lst);
	removeTail(lst);
	printListFromTail(lst);
	insertToHead(lst,5);
	insertToHead(lst,6);
	insertToHead(lst,3);
	insertToTail(lst,1);
	insertToTail(lst,2);
	insertAfterKth(lst,4,1);
	printListFromHead(lst);
	removeElementKth(lst,2);
	printListFromHead(lst);
	printListFromTail(lst);
	removeElementKth(lst,0);
	printListFromHead(lst);
	removeElementKth(lst,3);
	printListFromHead(lst);
	int d = 5;
	while(d--){
		insertToTail(lst,2);	
	}
	printListFromHead(lst);
	removeAllValueK(lst,2);
	printListFromHead(lst);
	return 0;
}

Node* makeNewNode(data d){
	Node* t = NULL;
	t = (Node*) malloc(sizeof(Node));
	if(t==NULL){
		printf("Not enough memory. \n");
		exit(0);
	}
	t->d = d;
	t->pNext = NULL;
	t->pPre = NULL;
	return t;
}

DoubleList* init(){
	DoubleList* list = NULL;
	list = (DoubleList*) malloc(sizeof(DoubleList));
	if(list == NULL){
		printf("Not enough memory.\n");
		exit(0);
	}
	list->pHead = NULL;
	list->pTail = NULL;
	list->size = 0;
	return list;
}

void insertToHead(DoubleList* list, data d){
	Node* t = makeNewNode(d);
	if(list->pHead == NULL){
		list->pHead = t;
		list->pTail = t;
	}
	else{
		list->pHead->pPre = t;
		t->pNext = list->pHead;
		list->pHead = t;
		list->pHead->pPre = NULL;
	}
	list->size++;
}
 
 void insertToTail(DoubleList* list, data d){
 	Node* t = makeNewNode(d);
 	if(list->pHead == NULL){
 		list->pHead = t;
 		list->pTail = t;
	 }
	 else{
	 	list->pTail->pNext = t;
	 	t->pPre = list->pTail;
	 	list->pTail = t;
	 	list->pTail->pNext = NULL;
	 }
	 list->size++;
 }
 
 void insertAfterKth(DoubleList* list, data d, int k){
 	Node* t = makeNewNode(d);
 	int i = 0; Node* temp = list->pHead;
 	while(temp!= NULL && i!= k){
 		temp = temp->pNext;
 		i++;
	 }
	if(temp!= NULL){
		Node* t1 = temp->pNext;
		temp->pNext = t;
		t->pPre = temp;
		t->pNext = t1;
		t1->pPre = t;
		list->size++;
	} 
 }
 
 void changeValueKth(DoubleList* list, data d, int k){
 	Node* t = list->pHead;
 	int i = 0;
 	while(t!= NULL && i!= k){
 		t = t->pNext;
 		i++;
	 }
	 if(t!= NULL) t->d = d;
 }
 
 void removeHead(DoubleList* list){
 	if(list->size == 0) return;
 	if(list->size == 1) {
 		Node* t = list->pHead;
 		list->pHead = NULL;
 		list->pTail = NULL;
 		list->size = 0;
 		free(t);
 		return;
	}
	Node* t = list->pHead;
	Node* t1 = list->pHead->pNext;
	t1->pPre = NULL;
	t->pNext = NULL;
	list->pHead = t1;
	free(t);
	list->size--;
 }
 
 void removeTail(DoubleList* list){
 	if(list->size == 0) return;
 	if(list->size == 1) {
 		Node* t = list->pHead;
 		list->pHead = 0;
 		list->pTail = 0;
 		list->size = 0;
 		free(t);
 		return;
	}
	 Node* t = list->pTail;
	 Node* t1 = list->pTail->pPre;
	 t1->pNext = NULL;
	 t->pPre = NULL;
	 list->pTail = t1;
	 free(t);
	 list->size--;
 }
 
 void removeElementKth(DoubleList* list, int k){
 	Node* p = list->pHead;
 	int i = 0;
 	if(k == 0) {
 		removeHead(list);
 		return;
	}
 	if(k == list->size - 1) {
 		removeTail(list);
 		return;
	 }
 	while(p!= NULL && i!= k){
 		p = p->pNext;
 		i++;
	}
	if(p!= NULL){
		Node* t1 = p->pPre;
		Node* t2 = p->pNext;
		p->pNext = NULL;
		p->pPre = NULL;
		t1->pNext = t2;
		t2->pPre = t1;
		free(p);
		list->size--;
	}
	
 }
 
 void removeAllValueK(DoubleList* list, int k){
 	if(list->size == 0) return;
	while(list->pHead != NULL && list->pHead->d == k){
		Node* t = list->pHead;
		t->pNext->pPre = NULL;
		list->pHead = t->pNext;
		t->pNext = NULL;
		free(t);
		list->size--;
	}
	if(list->pHead == NULL){
		list->pTail = NULL;
		return;
	}
	Node* t = list->pHead;
	while(t->pNext!= NULL){
		if(t->pNext->d == k){
			Node* t1 = t->pNext;
			t->pNext = NULL;
			t1->pPre = NULL;
			while(t1->d == k){
				Node* t2 = t1;
				t1 = t1->pNext;
				t2->pNext = NULL;
				if(t1!= NULL) t1->pPre = NULL;
				free(t2);
				list->size--;
				if(t1 == NULL) break; 
			}
			t->pNext = t1;
			if(t1!= NULL) t1->pPre = t;
		}
		t = t->pNext;
		if(t == NULL) break;
	}
 }
 
 void printListFromHead(DoubleList* list){
	Node* t = list->pHead;
	while(t!= NULL){
		printf("%d ",t->d);
		t = t->pNext;
	}
	printf("\n");
}

 void printListFromTail(DoubleList* list){
	Node* t = list->pTail;
	while(t!= NULL){
		printf("%d ",t->d);
		t = t->pPre;
	}
	printf("\n");
}



