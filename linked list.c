#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _NODE {
	char DATA;
	struct _NODE *LINK;
}NODE;

NODE *head;
void InsertNodeAtFront(int a);
void InsertNodeAtBack(int b);
void PrintList();
void DeleteNodeAtFront();
void DeleteNodeAtBack();

int main() {
	InsertNodeAtFront(10);
	InsertNodeAtFront(20);
	InsertNodeAtFront(30);
	InsertNodeAtBack(40);
	InsertNodeAtBack(50);

	PrintList();

	DeleteNodeAtFront();
	DeleteNodeAtFront();
	DeleteNodeAtBack();
	PrintList();
	return 0;
}

void InsertNodeAtFront(int a) {
	NODE *new = NULL;
	new = (NODE *)malloc(sizeof(NODE));
	new->DATA = a;
	new->LINK = head;
	head = new;
}

void InsertNodeAtBack(int b) {
	NODE *new = NULL;
	new = (NODE *)malloc(sizeof(NODE));
	NODE *ptr = NULL;
	ptr = head->LINK;
	new->DATA = b;
	new->LINK = NULL;
	while (ptr->LINK != NULL)
	{
		ptr = ptr->LINK;
	}
	ptr->LINK = new;
}

void PrintList() {
	NODE *ptr;
	ptr = head;
	while (ptr != NULL){
		printf("%d ", ptr->DATA);
		ptr = ptr->LINK;
	}
	printf("\n");
}

void DeleteNodeAtFront() {
	NODE *ptr = NULL;
	ptr = head;
	head = head->LINK;
	free(ptr);
}

void DeleteNodeAtBack() {
	NODE *ptr = NULL;
	NODE *ptr1 = NULL;
	ptr = head->LINK;
	while (1)	{
		if (ptr->LINK->LINK == NULL)
			break;
		else
			ptr = ptr->LINK;
	}
	ptr1 = ptr->LINK;
	ptr->LINK = NULL;
	free(ptr1);
}

