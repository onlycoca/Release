#include <stdio.h>
#include <string.h>
char* new_strncpy(char **to_string, const char *from_string, int size);

void main() {
	char *to_string = NULL;
	char from_string[60];
	void *new;
	int size, n;

	printf("input str : ");
	scanf("%50[^\n]", from_string);
	printf("input size = ");
	scanf("%d", &size);

	printf("before p = ");
	printf("%s\n", to_string);

	new = new_strncpy(&to_string, from_string, size);

	printf("after p = ");
	printf("%s\n", to_string);

	printf("before p = %s\n", to_string);
	new_strncpy(&to_string, "Hello", 5);
	printf("after p = %s\n", to_string);
	char *p2 = (char*)malloc(sizeof(char) * 2);
	char *p3 = (char*)malloc(sizeof(char) * 10);
	new_strncpy(&p2, "HELLO WORLD!", 5);
	new_strncpy(&p3, "I need OpenLab!" +7, 10);
	printf("p2 = %s\n", p2);
	printf("p3 = %s\n", p3);

	return 0;
}

char* new_strncpy(char **to_string, const char *from_string, int size) {
	int size_from = strlen(from_string);
	if (*to_string == NULL) {
		if (size == 0) {
			size = size_from;
		}
		*to_string = (char*)malloc(sizeof(char)*(size+1));
		// size가 0일 경우 s
		// *to_string에 size+1만큼 메모리 할당
	}
	else if (strlen(*to_string) <= size) {
		if (size == 0) {
			size = size_from;
		}
		*to_string = (char*)realloc(*to_string, sizeof(char)*(size + 1));
		// size가 0일 경우 from_string의 사이즈만큼 
		// *to_string에 size+1만큼 재할당
	}

	if (size_from > size) {
		int i;
		for (i = 0; i < size; i++) {
			(*to_string)[i] = from_string[i];
		}
		(*to_string)[size] = '\0';
		// 하나씩 옮겨주되 끝에 널문자를 넣어준다.
	}
	else if (size_from <= size) {
		strcpy(*to_string, from_string);
		// strcpy와 동일한 기능
	}
	return *to_string;
}