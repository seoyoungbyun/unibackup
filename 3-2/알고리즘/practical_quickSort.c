#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 17

void swap(int A[], int i, int j) {
	int tmp = A[i];
	A[i] = A[j];
	A[j] = tmp;
}

int traditionalPartition(int A[], int p, int r)
{
	int x = A[r];
	int i = p - 1;

	for (int j = p; j < r; j++)
	{
		if (A[j] <= x)
		{
			i += 1;
			swap(A, i, j);
		}
	}

	swap(A, i + 1, r);

	return i + 1;
}

void quickSort(int A[], int p, int r) {
	if (p < r) {
		int q = traditionalPartition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

void insertionSort(int A[], int p, int q) {
	for (int i = p + 1; i < q; i++)
	{
		int j;
		for (j = p; j < i; j++)
			if (A[j] > A[i])
				break;
		int m = A[i];

		for (int k = i; k > j; k--)
			A[k] = A[k - 1];

		A[j] = m;
	}
}

void partition(int A[], int* p1, int* p2) {
	if (A[*p1] > A[*p2]) {
		swap(A, *p1, *p2);
	}

	int pivot1 = A[*p1];
	int pivot2 = A[*p2];

	int l = *p1;
	int g = *p2;

	int k = *p1;
	for (; k <= g; k++) {
		if (A[k] < pivot1) {
			l++;
			swap(A, k, l);
		}
		else if (A[k] > pivot2) {
			g--;
			swap(A, k, g);
			if (k != g)
				k--;
		}
	}

	swap(A, *p1, l);
	swap(A, *p2, g);

	*p1 = l;
	*p2 = g;

}
void dualPivotQuickSort(int A[], int p, int q) {
	if (q - p < n)
		insertionSort(A, p, q);
	else {
		if (p < q) {
			int p1 = p;
			int p2 = q;
			partition(A, &p1, &p2);

			dualPivotQuickSort(A, p, p1 - 1);
			dualPivotQuickSort(A, p1 + 1, p2 - 1);
			dualPivotQuickSort(A, p2 + 1, q);
		}
	}
}
int main(void) {
	int arr_len[] = {10000, 100000, 200000, 400000, 800000, 1600000, 3200000, 6400000};
	
	for (int i = 0; i < sizeof(arr_len) / sizeof(int); i++) {
		int size = arr_len[i];
		int* arr1 = (int*)malloc(size * sizeof(int));
		int* arr2 = (int*)malloc(size * sizeof(int));

		if (arr1 == NULL)
			printf("malloc error");

		if (arr2 == NULL)
			printf("malloc error");

		srand(time(NULL));

		for (int j = 0; j < size; j++){
			int num = rand();
			arr1[j] = num;
			arr2[j] = num;
		}

		clock_t start = clock();
		quickSort(arr1, 0, size - 1);
		clock_t end = clock();
		float time = (float)(end - start) / CLOCKS_PER_SEC;
		printf("%d %f\t", size, time);

		start = clock();
		dualPivotQuickSort(arr2, 0, size - 1);
		end = clock();

		time = (float)(end - start) / CLOCKS_PER_SEC;
		printf("%d %f\n", size, time);

		free(arr1);
		free(arr2);
	}
}