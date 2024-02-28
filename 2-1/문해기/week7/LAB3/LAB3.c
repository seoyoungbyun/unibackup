#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void sort(int arr[], int n) {
	int i, j;

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
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
		arr[i] = rand() % 1000;
		printf("%d ", arr[i]);
	}
	printf("\n");

	sort(arr, n);
	printf("정렬된 후:\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr);
}