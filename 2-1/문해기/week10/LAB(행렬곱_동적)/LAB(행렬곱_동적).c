#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void matrixMul(int** a, int** c, int** x, int ar, int ac, int cr, int cc) {
	for (int i = 0; i < ar; i++)
		for (int j = 0; j < cc; j++)
			x[i][j] = 0;
	for (int i = 0; i < ar; i++)
		for (int j = 0; j < cc; j++)
			for (int k = 0; k < ac; k++)
			x[i][j] += a[i][k] * c[k][j];
}
void matrixReverse(int** a, int** r, int ar, int ac) {
	for (int i = 0; i < ar; i++)
		for (int j = 0; j < ac; j++)
			r[j][i] = a[i][j];
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
	int** A, ** C, **R;
	int** X; // A + B
	int aRow, aCol, cRow, cCol;
	int i, j;

	printf("Enter ��� A�� ��� ���� ����: ");
	scanf("%d %d", &aRow, &aCol);
	printf("Enter ��� C�� ��� ���� ����(C�� ���� %d�̾��): ", aCol);
	scanf("%d %d", &cRow, &cCol);

	A = (int**)malloc(sizeof(int*) * aRow);
	C = (int**)malloc(sizeof(int*) * cRow);
	X = (int**)malloc(sizeof(int*) * aRow);
	R = (int**)malloc(sizeof(int*) * aCol);
	
	for (i = 0; i < aRow; i++) {
		A[i] = (int*)malloc(sizeof(int) * aCol);
		X[i] = (int*)malloc(sizeof(int) * cCol);
	}
	for (i = 0; i < cRow; i++)
		C[i] = (int*)malloc(sizeof(int) * cCol);
	for (i = 0; i < aCol; i++)
		R[i] = (int*)malloc(sizeof(int) * aRow);

	printf("%d X %d ��� A �Է�:\n", aRow, aCol);
	readMatrix(A, aRow, aCol);
	printf("\n%d X %d ��� C �Է�:\n", cRow, cCol);
	readMatrix(C, cRow, cCol);
	matrixMul(A, C, X, aRow, aCol, cRow, cCol);
	matrixReverse(A, R, aRow, aCol);

	printf("\n��İ�:\n");
	printMatrix(X, aRow, cCol);
	printf("\n��ġ���:\n");
	printMatrix(R, aCol, aRow);

	for (i = 0; i < aRow; i++)
	{
		free(A[i]);
		free(X[i]);
	}
	for (i = 0; i < cRow; i++)
		free(C[i]);
	for (i = 0; i < aCol; i++)
		free(R[i]);

	free(A);
	free(C);
	free(X);
	free(R);
}