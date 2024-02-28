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
int selection(int arr[], int p, int r, int idx) {
	int q;

	if (p < r) {
		q = partition(arr, p, r);
		if (q == idx)
			return arr[q];
		else if (q > idx)
			selection(arr, 0, q - 1, idx);
		else
			selection(arr, q + 1, r, idx);
	}
}
int main()
{
	int n, num;

	srand(time(NULL));

	printf("Enter the number of numbers: ");
	scanf("%d", &n);
	printf("몇번째로 작은 수: ");
	scanf("%d", &num);

	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		arr[i] = rand() % 1000;

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	int output = selection(arr, 0, n - 1, num - 1);
	printf("%d번째 작은 수는 %d\n", num, output);
	
	free(arr);
}