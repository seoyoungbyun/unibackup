#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int n, int* bucket, int bucketSize, int k) {
	int i, lastIndex, smallest, index;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%d ", bucket[i]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex];

	for (index = smallest; index < n; index++) {
		bucket[lastIndex + 1] = index;
		pick(n, bucket, bucketSize, k - 1);
	}
}
int main(void) {
	int n = 4;
	int num;

	printf("ют╥б: ");
	scanf("%d", &num);
	
	int *bucket = (int*)malloc(sizeof(int) * num);

	pick(n, bucket, num, num);

	free(bucket);
}