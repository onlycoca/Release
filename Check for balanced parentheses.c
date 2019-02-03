#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int 
#define true 1
#define false 0

typedef struct {
	int count;
	struct node* top;
}STACK;

typedef struct node {
	char data;
	struct node* link;
}STACK_NODE;

bool push(STACK* pStack, char ch);
bool pop(STACK* pStack, char* ch);

int main(void) {
	STACK pStack;
	char str[100];
	scanf("%s", str);
	solve(str);
	if (solve(str)==1) {
		printf("Matched Parentheses!\n");
	}
	else if (solve(str)==0){
		printf("Unmatched Parentheses!\n");
	}
	return 0;
}

bool push(STACK* pStack, char ch) {
	STACK_NODE* pNew;
	bool success;
	pNew = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	if (!pNew) {
		success = false;
	}
	else {
		pNew->data = ch;
		pNew->link = pStack->top;
		pStack->top = pNew;
		pStack->count++;
		success = true;
	}
	return success;
}

bool pop(STACK* pStack, char* ch) {
	STACK_NODE *pDlt;
	bool success;
	if (pStack->top) {
		success = true;
		*ch = pStack->top->data;
		pDlt = pStack->top;
		pStack->top = pStack->top->link;
		pStack->count--;
		free(pDlt);
	}
	else {
		success = false;
	}
	return success;
}

int empty(STACK* pStack) {
	if (pStack->count == 0)
		return 1;
	else
		return 0;
}

int solve(const char* str) {
	STACK* pStack = (STACK*)calloc(1, sizeof(STACK));
	pStack->top = NULL;
	pStack->count = 0;
	char ch = 0;
	for (int i = 0; str[i]; i++) {
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
			push(pStack, str[i]);
		}
		if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
			if (empty(pStack)) {
				free(pStack);
				return false;
			}
			if (pop(pStack, &ch) == false) return 0;
			if (str[i] == ')' && ch == '(') continue;
			if (str[i] == '}' && ch == '{') continue;
			if (str[i] == ']' && ch == '[') continue;
			return false;
		}
	}
	int ans = empty(pStack);

	STACK_NODE* del = pStack->top;
	STACK_NODE* temp = NULL;
	while (del) {
		temp = del;
		del = del->link;
		free(temp);
	}
	free(pStack);
	return ans;
}

