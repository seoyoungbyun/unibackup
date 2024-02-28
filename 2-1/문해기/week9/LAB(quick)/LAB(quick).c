#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int partition(int arr[], int p, int r)
{
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
void quickSort(int arr[], int p, int r) {
	int q;

	if (p < r) {
		q = partition(arr, p, r);//오른쪽 왼쪽 분류
		quickSort(arr, p, q - 1);//왼쪽 정렬
		quickSort(arr, q + 1, r);//오른쪽 정렬
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

	if (arr == NULL)
		return;

	for (int i = 0; i < n; i++) {
		arr[i] = rand();
		printf("%d ", arr[i]);
	}
	printf("\n");

	quickSort(arr, 0, n - 1);
	printf("정렬된 후:\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr);
}