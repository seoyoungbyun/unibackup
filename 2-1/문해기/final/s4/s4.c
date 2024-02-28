#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long partition(char A[], long long p, long long r, long long length) {
    long long i, j;
    long long t;

    i = p - 1;

    for (j = p; j < r; j++) {
        if (A[j] < A[r]) {
            i++;
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }

    i++;
    t = A[i];
    A[i] = A[r];
    A[r] = t;


    return i;
}

void quickSort(char A[], long long p, long long r, long long length) {
    if (p < r) {
        long long q = partition(A, p, r, length);
        quickSort(A, p, q - 1, length);
        quickSort(A, q + 1, r, length);
    }
}

int main(void) {
    char s[500001];
    long long i, n;

    scanf("%s", s);

    long long length = strlen(s);

    for (int i = 0; i < length; i++) {
        if (s[i] < 'A')
            s[i] += 30;
        else
            s[i] -= 60;
    }
    quickSort(s, 0, length - 1, length);


    for (int i = 0; i < length; i++) {
        if (s[i] < 70)
            s[i] += 60;
        else
            s[i] -= 30;
    }

    printf("%s", s);

    return 0;
}