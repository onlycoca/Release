#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
	char command[10];
	struct node* next;
}QUEUE_NODE;

typedef struct {
	QUEUE_NODE *front;
	int count;
	QUEUE_NODE* rear;
}QUEUE;

int CheckCommand(char* command);
void EnqueueCommand(QUEUE* pQueue, char* dataIn);
int DequeuePrint(QUEUE* pQueue, char* dataOut);

int main(void){
	char command[10];
	QUEUE* pQueue;
	pQueue = (QUEUE*)malloc(sizeof(QUEUE));
	pQueue->front = NULL;
	pQueue->count = 0;
	pQueue->rear = NULL;
	char del[10];
	int result;
	while (1)	{
		printf(">>");
		scanf("%s", command);
		CheckCommand(command);
		if (CheckCommand(command) == 1) {
			if (strcmp(command, "q") == 0 || strcmp(command, "quit") == 0)
				break;
			else {
				if (strcmp(command, "history") == 0 || strcmp(command, "h") == 0)
					while (1) {
						result = DequeuePrint(pQueue, del);
						if (result == 0)
							break;
						else
							printf("%s\n", del);
					}
				else {
					if (CheckCommand(command) == 1) {
						printf("%s\n", command);
					}
					EnqueueCommand(pQueue, command);
				}
			}
		}
	}
}

int CheckCommand(char* command) {
	if (strcmp(command, "help") != 0 && strcmp(command, "dir") != 0 && strcmp(command, "mkdir") != 0 && strcmp(command, "cd") != 0 && strcmp(command, "history") != 0 && strcmp(command, "h") != 0 && strcmp(command, "quit") != 0 && strcmp(command, "q") != 0) {
		return 0;
	}
	else return 1;
}

void EnqueueCommand(QUEUE* queue, char* data){
	QUEUE_NODE* pNew;
	pNew = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));
	strcpy(pNew->command, data);
	pNew->next = NULL;
	if (queue->count == 0)
		queue->front = pNew;
	else
		queue->rear->next = pNew;
	(queue->count)++;
	queue->rear = pNew;
}

void printQueue(QUEUE *queue){
	QUEUE_NODE* ptr;
	int size = 0;
	ptr = queue->front;
	size = queue->count;
	for (int i = 0; i < size; i++) {
		printf("%s\n", ptr->command);
		ptr = ptr->next;
	}
}

int DequeuePrint(QUEUE* pQueue, char* dataOut){
	QUEUE_NODE* ptr;
	if (pQueue->count == 0)
		return 0;
	else{
		ptr = pQueue->front;
		strcpy(dataOut, ptr->command);
		(pQueue->count)--;
		pQueue->front = pQueue->front->next;
		free(ptr);
		return 1;
	}
}