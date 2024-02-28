#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void matrixMul(int** a, int** b, int** x, int r, int c) {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			x[i][j] = a[i][j] + b[i][j];
}
void printMatrix(int** a, int r, int c) { 
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			printf("%3d ", a[i][j]);
		printf("\n");
	}
}
void readMatrix(int** a, int r, int c) { 
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			scanf("%d", &a[i][j]);
}
int main(void)
{
	int** A, ** B;
	int** X; // A + B
	int aRow, aCol;
	int i, j;
	
	printf("Enter ��� A�� ��� ���� ����: ");
	scanf("%d %d", &aRow, &aCol);
	
	// �������� ��� A(aRow x aCol)�� B(aRow x aCol)��
	// X(aRow x aCol)�� ����
	A = (int**)malloc(sizeof(int*) * aRow);
	B = (int**)malloc(sizeof(int*) * aRow);
	X = (int**)malloc(sizeof(int*) * aRow);
	for (i = 0; i < aRow; i++)
	{
		A[i] = (int*)malloc(sizeof(int) * aCol);
		B[i] = (int*)malloc(sizeof(int) * aCol);
		X[i] = (int*)malloc(sizeof(int) * aCol);
	}
	// A B ��İ� �Է� �� X ��� �ʱ�ȭ
	printf("(%d X %d) ��� A �Է�:\n", aRow, aCol);
	readMatrix(A, aRow, aCol);
	printf("(%d X %d) ��� B �Է�:\n", aRow, aCol);
	readMatrix(B, aRow, aCol);
	matrixMul(A, B, X, aRow, aCol);
	
	printf("�����:\n");
	printMatrix(X, aRow, aCol); 
	printf("\n");

	for (i = 0; i < aRow; i++)
	{
		free(A[i]);
		free(B[i]);
		free(X[i]);
	}
	free(A);
	free(B);
	free(X);
}