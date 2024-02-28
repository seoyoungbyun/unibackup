#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define DEFAULT 0
#define LE 1
#define UP 2

#define NOT_AVAILABLE 0
#define AVAILABLE 1

void print_path(int i, int j, int** BP) {
    if (BP[i][j] == UP)
        print_path(i - 1, j, BP);
    else if (BP[i][j] == LE)
        print_path(i, j - 1, BP);

    printf("<%d,%d> ", i, j);
}

int matrixPath(int** m, int r, int c, int i, int j, int** M, int** M1, int** bp)
{
    if (M1[i][j] != NOT_AVAILABLE) return M[i][j];
    M1[i][j] = AVAILABLE;

    if (i == 0 && j == 0) {
        M[i][j] = m[i][j];
        return m[i][j];
    }
    else if (i == 0) {
        M[i][j] = matrixPath(m, r, c, 0, j - 1, M, M1, bp) + m[i][j];
        bp[i][j] = LE;
        return M[i][j];
    }
    else if (j == 0) {
        M[i][j] = matrixPath(m, r, c, i - 1, 0, M, M1, bp) + m[i][j];
        bp[i][j] = UP;
        return M[i][j];
    }
    else
    {
        int a, b;
        a = matrixPath(m, r, c, i - 1, j, M, M1, bp);
        b = matrixPath(m, r, c, i, j - 1, M, M1, bp);
        M[i][j] = ((a < b) ? a : b) + m[i][j];
        if (a < b)
            bp[i][j] = UP;
        else
            bp[i][j] = LE;
        return M[i][j];
    }
}

int main(void)
{
    int** m, ** M, ** M1, ** bp; // M은 메모
    int i, j, r, c;
    //r = c = 4; // 4x4 matrix

    printf("Enter row and column(r c): ");
    scanf("%d %d", &r, &c);

    m = (int**)malloc(sizeof(int*) * r);
    M = (int**)malloc(sizeof(int*) * r);
    M1 = (int**)malloc(sizeof(int*) * r);
    bp = (int**)malloc(sizeof(int*) * r);

    for (i = 0; i < r; i++) {
        m[i] = (int*)malloc(sizeof(int) * c);
        M[i] = (int*)malloc(sizeof(int) * c);
        M1[i] = (int*)malloc(sizeof(int) * c);
        bp[i] = (int*)malloc(sizeof(int) * c);
    }

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            scanf("%d", &m[i][j]);
            M1[i][j] = NOT_AVAILABLE; //메모 초기화
            bp[i][j] = DEFAULT; //메모 초기화
        }

    printf("%d\n", matrixPath(m, r, c, 3, 3, M, M1, bp));
    print_path(r - 1, c - 1, bp);
    printf("\n");

    for (int i = 0; i < c; i++)
    {
        free(m[i]);
        free(M[i]);
        free(M1[i]);
        free(bp[i]);
    }
    free(m);
    free(M);
    free(M1);
    free(bp);
}