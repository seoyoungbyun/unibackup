#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int arr[], int arr2[], int p, int q, int r)
{
	int i, j, t;

	i = p;
	j = q + 1;
	t = p;

	while (i <= q && j <= r) {
		if (arr[i] < arr[j]) {
			arr2[t] = arr[i];
			t++;
			i++;
		}
		else {
			arr2[t] = arr[j];
			t++;
			j++;
		}
	}

	if (j > r) {
		for (; i <= q; i++, t++)
			arr2[t] = arr[i];
	}
	else {
		for (; j <= r; j++, t++)
			arr2[t] = arr[j];
	}

	for (i = p; i <= r; i++)
		arr[i] = arr2[i];
}
void mergeSort(int arr[], int arr2[], int p, int r) {
	int q;

	if (p < r) {
		q = (p + r) / 2;
		mergeSort(arr, arr2, p, q);
		mergeSort(arr, arr2, q + 1, r);
		merge(arr, arr2, p, q, r);
	}
}
int main(void) {
	int n;

	srand(time(NULL));

	printf("Enter a number: ");
	scanf("%d", &n);

	if (n <= 0)
		return;

	int* arr = (int*)malloc(sizeof(int) * n);
	int* arr2 = (int*)malloc(sizeof(int) * n);
	if (arr == NULL || arr2 == NULL)
		return;

	for (int i = 0; i < n; i++) {
		arr[i] = rand();
		printf("%d ", arr[i]);
	}
	printf("\n");

	mergeSort(arr, arr2, 0, n - 1);
	printf("정렬된 후:\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr);
	free(arr2);
}