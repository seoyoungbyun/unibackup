#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int pick(int num[], int numSize, int* bucket, int bucketSize, int k, int n) {
	int i, lastIndex, smallest, index;
	int sum = 0;
	int count = 0;

	lastIndex = bucketSize - k - 1;
	for (int i = 0; i < lastIndex + 1; i++) {
		sum += num[bucket[i]];
	}

	if (sum > n)
		return 0;

	if (sum == n)
		return 1;

	if (k == 0)
		return 0;

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex];

	for (index = smallest; index < numSize; index++) {
		bucket[lastIndex + 1] = index;
		count += pick(num, numSize, bucket, bucketSize, k - 1, n);
	}

	return count;
}
int main(void) {
	int num[] = { 1, 2, 3 };
	int n;
	
	scanf("%d", &n);

	int* bucket = (int*)malloc(sizeof(int) * n); //동적할당

	int count = pick(num, 3, bucket, n, n, n);

	printf("%d\n", count);

	free(bucket);
}