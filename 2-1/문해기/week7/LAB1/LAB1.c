#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

	free(arr);
}