#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int matrixPath(int** m, int r, int c, int i, int j, int** M, int** M1)
{
    if (M1[i][j] != 0) return M[i][j];
    M1[i][j] = 1;

    if (i == 0 && j == 0) {
        M[i][j] = m[i][j];
        return M[i][j];
    }
    else if (i == 0) {
        M[i][j] = matrixPath(m, r, c, 0, j - 1, M, M1) + m[i][j];
        return M[i][j];
    }
    else if (j == 0) {
        M[i][j] = matrixPath(m, r, c, i - 1, 0, M, M1) + m[i][j];
        return M[i][j];
    }
    else
    {
        int a, b;
        a = matrixPath(m, r, c, i - 1, j, M, M1);
        b = matrixPath(m, r, c, i, j - 1, M, M1);
        M[i][j] = ((a < b) ? a : b) + m[i][j];
        return M[i][j];
    }
}

int main(void)
{
    int** m, ** M, ** M1; // M은 메모
    int i, j, r, c;
    r = c = 4; // 4x4 matrix
    m = (int**)malloc(sizeof(int*) * r);
    M = (int**)malloc(sizeof(int*) * r);
    M1 = (int**)malloc(sizeof(int*) * r);
    for (i = 0; i < r; i++) {
        m[i] = (int*)malloc(sizeof(int) * c);
        M[i] = (int*)malloc(sizeof(int) * c);
        M1[i] = (int*)malloc(sizeof(int) * c);
    }
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            scanf("%d", &m[i][j]);
            M1[i][j] = 0; //메모 초기화
        }
    printf("%d\n", matrixPath(m, r, c, 3, 3, M, M1));
}