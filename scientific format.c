#include <stdio.h>
char* getScientificFormatString(char* strPtr);

void main() {
	char* strPtr = NULL;
	char *Ptr;
	printf("Input scientific format number : ");
	strPtr = (char*)malloc(sizeof(char) * 15);
	for (int i = 0; i < 15; i++) {
		scanf("%[^\n]c", &strPtr[i]);
	}
	Ptr = getScientificFormatString(strPtr);
	if (Ptr ==strPtr) {
		printf("|%20s|\n", strPtr);
	}
	if (Ptr == NULL) {
		printf("|%-20s|\n", strPtr);
	}
}

char* getScientificFormatString(char* strPtr) {
	int cnt, i;
	for (cnt = 0; ; cnt++) {
		if (strPtr[cnt] == '\n') break;
	}
	
		for (i = 0; i < cnt; i++) {
			if ((strPtr[i] >= 'a' && strPtr[i] < 'e') || (strPtr[i] > 'e' && strPtr[i] <= 'z') || (strPtr[i] >= 'A' && strPtr[i] < 'E') || (strPtr[i] > 'E' && strPtr[i] <= 'Z')) {
			
				strPtr[i] = '\0';
				return NULL;
			}
			if (strPtr[i] == 'E' || strPtr[i] == 'e') {
				if (strPtr[i + 1] == '+' || strPtr[i + 1] == '-') {
					if (strPtr[i + 2] >= '0' && strPtr[i + 2] <= '9') {
						if (strPtr[i + 3] >= '0' && strPtr[i + 3] <= '9') {
							return strPtr;
						}
					}
				}
			}
		}
	
	return NULL;
}
