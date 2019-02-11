#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int** transpose(int** matrix, int m, int n);

void main() {
	srand(time(NULL));
	int row, col, i, j;
	int** matrix , **trans;
	printf("Number of Rows : ");
	scanf("%d", &row);
	printf("Number of Cols : ");
	scanf("%d", &col);
	matrix = (int**)malloc(sizeof(int*)*(row));
	for (i = 0; i < row; i++) {
		matrix[i] = (int*)malloc(sizeof(int)*col);
	}
	printf("Before\n");
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%2d ", matrix[i][j] = rand() % 100 + 1);
		}
		printf("\n");
	}
	trans = transpose(matrix, row, col);
	printf("After\n");
	for (i = 0; i < col; i++) {
		for (j = 0; j < row; j++) {
			printf("%2d ", trans[i][j]);
		}
		printf("\n");
	}
}

int** transpose(int** matrix, int m, int n) {
	int ** trans;
	int i, j;
	trans = (int**)malloc(sizeof(int*)*(n));
	for (i = 0; i < n; i++) {
		trans[i] = (int*)malloc(sizeof(int)*m);
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			trans[j][i] = matrix[i][j];
		}
	}
	return trans;
}