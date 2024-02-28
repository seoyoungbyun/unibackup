#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int partition(int* arr, int p, int r) {//Á¤·Ä
    int i, j;
    int temp;

    i = p - 1;

    for (j = p; j < r; j++) {
        if (arr[j] < arr[r]) {
            i++;
            //arr[i] <-> arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    i++;
    temp = arr[i];
    arr[i] = arr[r];
    arr[r] = temp;

    return i;
}
void quickSort(int* arr, int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}
int search(int arr[], int low, int high, int key) {
    int mid;

    if (low > high)
        return -1;

    mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] > key)
        return search(arr, low, mid - 1, key);
    else
        return search(arr, mid + 1, high, key);
}

int main(void) {
    int n, m;

    scanf("%d", &m);
    int* M = (int*)malloc(sizeof(int) * m);

    for (int i = 0; i < m; i++)
        scanf("%d", &M[i]);

    quickSort(M, 0, m - 1);

    scanf("%d", &n);
    int* N = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        scanf("%d", &N[i]);

    int count = 0;
    for (int i = 0; i < n; i++) {
        int num = search(M, 0, m - 1, N[i]);

        if (num != -1)
            count++;
    }

    printf("%d\n", count);

    free(N);
    free(M);
}