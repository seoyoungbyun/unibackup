#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void change(int a[], int b[], int n, int try) {
	int max, min;

	max = a[0];
	int maxIndex = 0;
	for (int i = 1; i < n - try; i++) {
		if (max < a[i]) {
			max = a[i];
			maxIndex = i;
		}
	}

	min = b[0];
	int minIndex = 0;
	for (int i = 1; i < n - try; i++) {
		if (min > b[i]) {
			min = b[i];
			minIndex = i;
		}
	}
	//배열 A B 바꾸기
	b[minIndex] = max;
	a[maxIndex] = min;
	//바꾼 값 정렬
	a[maxIndex] = a[n - try - 1];
	a[n - try - 1] = min;
	b[minIndex] = b[n - try - 1];
	b[n - try - 1] = max;
}
int main(void) {
	int n, k;
	int a[100], b[100];

	scanf("%d", &n);
	scanf("%d", &k);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);

	for (int i = 0; i < k; i++)
		change(a, b, n, i);

	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += b[i];

	printf("%d", sum);
}