#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int partition(int* A, int p, int r) {
    int i, j;
    int t;

    i = p - 1;

    for (j = p; j < r; j++) {
        if (A[j] < A[r]) {
            i++;
            //A[i] <-> A[j]
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
void quickSort(int* A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}
int binarySearch(int arr[], int fir, int last, int key) {
    int mid;
    if (fir > last)
        return -1;
    mid = (fir + last) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] > key)
        return binarySearch(arr, fir, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, last, key);
}
int main(void) {
    int n;
    int m;
    int* arrn, * arrm;
    int i, j, c = 0;

    scanf("%d", &m);// 마트 물건
    arrm = (int*)malloc(sizeof(int) * m);
    for (i = 0; i < m; i++) {
        scanf("%d", &arrm[i]);
    }

    scanf("%d", &n);//내가 구입할 물건
    arrn = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arrn[i]);
    }
    quickSort(arrm, 0, m - 1);

    for (i = 0; i < n; i++) {
        int n = arrn[i];
        int rslt = binarySearch(arrm, 0, m - 1, n);
        if (rslt != -1)
            c++;
    }
    printf("%d", c);
    free(arrn);
    free(arrm);
    return 0;
}