#include <stdio.h>
#include <string.h>
void splitString(char *str, char *word1, char *word2);

void main() {
	char *str;
	char *word1 =NULL , *word2 =NULL;
	str = (char*)malloc(sizeof(char)*32);
	printf("input str : ");
	fgets(str, 32, stdin);
	str[strlen(str) - 1] = '\0';
	if (strlen(str) % 2 == 0) {
		word1 = (char*)malloc(sizeof(char)*(strlen(str) / 2));
		word2 = (char*)malloc(sizeof(char)*(strlen(str) / 2));
	}
	else {
		word1 = (char*)malloc(sizeof(char)*(strlen(str) / 2));
		word2 = (char*)malloc(sizeof(char)*((strlen(str) / 2) + 1));
	}
	splitString(str, word1, word2);
	printf("[%s] -> [%s] [%s]\n", str, word1, word2);
}

void splitString(char *str, char *word1, char *word2) {
	
	int i=0;
	if (strlen(str) % 2 == 0) {
		for (i = 0; i < strlen(str)/2; i++) {
			word1[i]=str[i];
		}
		word1[i] = '\0';	
		strcpy(word2, str + (strlen(str) / 2));
	}
	else {
		for (i = 0; i < (strlen(str)/2); i++) {
			word1[i] = str[i];
		}
		word1[i] = '\0';	
		strcpy(word2, str + (strlen(str) / 2));
	}
}