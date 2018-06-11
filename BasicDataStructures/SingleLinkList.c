#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
	int data;
	Node* pNext;
};

struct SLL
{
	Node* pHead;
	Node* pTail;
};

SLL* list = NULL;

void initSLL(SLL *list)
{
	list->pHead = list->pTail = NULL;
}

bool isSLLEmpty(SLL list)
{
	if (!list.pHead)
	{
		return true;
	}
	return false;
}

void viewSLL(SLL list)
{
	Node *pNode;
	if (isSLLEmpty(list))
	{
		printf("Single link list is empty\n");
	}
	else
	{
		pNode = list.pHead;
		while (pNode)
		{
			printf("%d\n", pNode->data);
			pNode = pNode->pNext;
		}
	}
}

Node *newNode(int k)
{
	Node *pNode;
	pNode = (Node*)malloc(1 * sizeof(Node));
	if (!pNode)
	{
		return NULL;
	}
	pNode->data = k;
	pNode->pNext = NULL;
	return pNode;
}

bool insertHead(SLL *list, Node *node)
{
	if (!node)
	{
		return false;
	}
	node->pNext = list->pHead;
	list->pHead = node;
	if (!list->pTail)
	{
		list->pTail = node;
	}
	return true;
}

bool insertTail(SLL *list, Node *node)
{
	if (!node)
	{
		return false;
	}
	if (!list->pHead)
	{
		list->pHead = list->pTail = node;
	}
	else
	{
		list->pTail->pNext = node;
		list->pTail = node;
	}
	return true;
}

void delHead(SLL *list)
{
	Node *pNode;
	pNode = list->pHead;
	if (pNode)
	{
		list->pHead = pNode->pNext;
		pNode->pNext = NULL;
		free(pNode);
		if (!list->pHead)
		{
			list->pTail = NULL;
		}
	}
}

void delTail(SLL *list)
{
	Node *pNode;
	pNode = list->pHead;
	if (!pNode)
	{
		return;
	}
	if (list->pHead == list->pTail)
	{
		list->pHead = list->pTail = NULL;
		free(pNode);
		return;
	}
	while (pNode->pNext != list->pTail)
	{
		pNode = pNode->pNext;
	}
	pNode->pNext = NULL;
	free(list->pTail);
	list->pTail = pNode;
}

void delList(SLL *list)
{
	while (!isSLLEmpty(*list))
	{
		delTail(list);
	}
}

int main(){
	list = (SLL*) malloc(sizeof(SLL));
	initSLL(list);
	if (isSLLEmpty(*list)) printf("Single link list is empty\n");
	insertHead(list, newNode(5));
	insertTail(list, newNode(6));
	_getch();
	return 0;
}