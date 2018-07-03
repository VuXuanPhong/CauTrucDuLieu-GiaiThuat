/*************************SOLVE TREE PROBLEM****************************************
When            Who         What
29/04/2018      Phong      Basic Data Structures single link list

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
	struct _node* next;
};

typedef struct _node Node;

struct _linklist{
	Node* head;
	Node* tail;
	int size;
};
typedef struct _linklist LinkList;

#define inf -10000000

//method:
LinkList* init();
Node* makeNewNode(data d);
void insertToHead(LinkList* list, data d);
void removeHead(LinkList* list);
void insertToTail(LinkList* list, data d);
void removeTail(LinkList* list);
void insertToAfterElementK(LinkList* list, int k, data d);
void removeElementKth(LinkList* list, int k);
void removeAllValueK(LinkList* list, data k);
data valueOfIndex(LinkList* list, int id);
void printList(LinkList* list);

int main(){
	LinkList* list = init();
	insertToHead(list,5);
	insertToHead(list,6);
	insertToHead(list,8);
	insertToTail(list,4);
	insertToTail(list,2);
	insertToTail(list,1);
	insertToAfterElementK(list,0,7);
	insertToAfterElementK(list,4,3);
	printList(list);
	removeHead(list);
	printList(list);
	removeTail(list);
	printList(list);
	removeElementKth(list,2);
	printList(list);
	removeElementKth(list,2);
	printList(list);
	removeElementKth(list,3);
	printList(list);	
	removeElementKth(list,1);
	printList(list);
	removeElementKth(list,0);
	printList(list);
	removeElementKth(list,0);
	printList(list);
	removeElementKth(list,0);
	printList(list);
	int d = 5;
	while(d--){
		insertToHead(list,5);
	}
	removeAllValueK(list,5);
	printList(list);
	insertToHead(list,3);
	insertToHead(list,5);
	insertToHead(list,4);
	insertToHead(list,3);
	insertToHead(list,3);
	insertToHead(list,4);
	insertToHead(list,5);
	insertToHead(list,3);
	insertToHead(list,3);
	insertToHead(list,3);
	insertToHead(list,4);
	insertToHead(list,6);
	insertToHead(list,3);
	printList(list);
	removeAllValueK(list,3);
	printList(list);
	return 0;
}

Node* makeNewNode(data d){
	Node* temp = NULL;
	temp = (Node*) malloc(sizeof(Node));
	if(temp == NULL) {
		printf("Not enough memory !\n");
		exit(0);
	}
	temp->d = d;
	temp->next = NULL;
	return temp;
}
LinkList* init(){
	LinkList* list = NULL;
	list = (LinkList*) malloc(sizeof(LinkList));
	if(list == NULL) {
		printf("Not enough memory!\n");
		exit(0);
	}
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return list;
}

void insertToHead(LinkList* list, data d){
	Node* t = makeNewNode(d);
	if(list->head == NULL){
		list->head = t;
		list->tail = t;
	}
	else{
		t->next = list->head;
		list->head = t;
	}
	list->size++;
}

void removeHead(LinkList* list){
	if(list->size==0) return;
	if(list->size==1){
		Node* t = list->head;
		list->head = NULL;
		list->tail = NULL;
		list->size--;
		free(t);
		return;
	}
	Node* temp = list->head;
	list->head = temp->next;
	temp->next = NULL;
	free(temp);
	list->size--;
}

void insertToTail(LinkList* list, data d){
	Node* t = makeNewNode(d);
	if(list->tail == NULL){
		list->head = t;
		list->tail = t;
	}
	else{
		list->tail->next = t;
		list->tail = t;
	}
	list->size++;
}

void removeTail(LinkList* list){
	if(list->size == 0) return;
	if(list->size == 1){
		Node* t = list->head;
		list->head = NULL;
		list->tail = NULL;
		free(t);
		list->size=0;
		return;
	}
	Node* temp = list->head;
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	Node* t = temp->next;
	temp->next = NULL;
	list->tail = temp;
	free(t);
	list->size--;
}

void insertToAfterElementK(LinkList* list, int k, data d){
	Node* temp = list->head;
	int i =0;
	while(i!=k && temp!= NULL){
		temp = temp->next;
		i++;
	}
	if(temp!= NULL){
		Node* t = makeNewNode(d);
		Node* t1 = temp->next;
		temp->next = NULL;
		temp->next = t;
		t->next = t1;
		list->size++;
	}
}

void removeElementKth(LinkList* list, int k){
	if(list->size == 0) return;
	int i =0;
	Node* t = list->head;
	while(i!=k && t!= NULL){
		t =t->next;
		i++;
	}
	if(t!= NULL){
		if(t->next == NULL) removeTail(list);
		else if(t->next->next == NULL){
			data d =  t->d;
			t->d = t->next->d;
			t->next->d = d;
			removeTail(list);
		}
		else{
			Node* t1 = t->next;
			Node* t2 = t->next->next;
			data d =  t->d;
			t->d = t1->d;
			t1->d = d;
			t1->next = NULL;
			t->next = NULL;
			t->next = t2;
			free(t1);
			list->size--;
		}
	}
}

void removeAllValueK(LinkList* list, data k){
	if(list->size == 0) return;
	while(list->head != NULL && list->head->d == k){
		Node* t = list->head;
		list->head = t->next;
		t->next = NULL;
		free(t);
		list->size--;
	}
	if(list->head == NULL){
		list->tail = NULL;
		return;
	}
	Node* t = list->head;
	while(t->next!= NULL){
		if(t->next->d == k){
			Node* t1 = t->next;
			while(t1->d == k){
				Node* t2 = t1;
				t1 = t1->next;
				t2->next = NULL;
				free(t2);
				list->size--;
				if(t1 == NULL) break;
			}
			t->next = t1;
		}
		t = t->next;
		if(t == NULL) break;
	}
}

data valueOfIndex(LinkList* list, int id){
	if(list->size == 0) return;
	Node* t = list->head;
	int i = 0;
	while(t != NULL && i!=id){
		t = t->next;
		i++;
	}
	if(t == NULL) return inf;
	return t->d;
}

void printList(LinkList* list){
	Node* temp = list->head;
	while(temp != NULL){
		printf("%d ",temp->d);
		temp = temp->next;
	}
	printf("\n");
}

