#include<stdio.h>
#include<stdlib.h>
void printByWord(char* str);

void main(void) {
	char* str = NULL;
	str = (char*)malloc(sizeof(char) * 41);
	printf("Input string : ");
	int i;
	for (i = 0; i < 40; i++)
	{
		scanf("%[^\n]c", &str[i]);
	}
	str[40] = '\0';
	printf("- Result -\n");
	printByWord(str);
}

void printByWord(char* str) {
	int i,count=0;
	if ((*str <= 'Z' && *str >= 'A') || (*str <= 'z' && *str >= 'a')) {
		while (str[count] != '\0')
		{
			count++;
		}
		for (i = 0; i < 40; i++) {
			if (str[i] == ' ') {
				str[i] = '\n';
			}
		}
		printf("\t");

		for (i = 0; i < count; i++)	{
			if (str[i] == '\n')	{
				printf("\n\t");
			}
			else	{
				printf("%c", str[i]);
			}
		}
		printf("\n");
	}
	else {
		*(str+20) = '\0';
		printf("\t");
		printf("%-40s", str);
		printf("\n");
	}
}
