#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int num[], int n, int* bucket, int bucketSize, int k, int money) {
	int i, lastIndex, smallest, index;

	lastIndex = bucketSize - k - 1;

	if (k == 0) {
		int sum = 0;
		for (int i = 0; i < lastIndex + 1; i++)
			sum += num[bucket[i]];

		for (i = 0; i < bucketSize; i++)
		{
			if (sum == money) {
				for (i = 0; i < bucketSize; i++)
					if (num[bucket[i]] != 0)
						printf("%d ", num[bucket[i]]);

				printf("\n");
			}
		}
		return;
	}

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex];

	for (index = smallest; index < n; index++) {
			bucket[lastIndex + 1] = index;
			pick(num, n, bucket, bucketSize, k - 1, money);
		}
}
int main(void) {
	int num[] = { 1000, 5000, 10000, 0};
	int money;

	printf("입력: ");
	scanf("%d", &money);

	int n = money / 1000;
	int* bucket = (int*)malloc(sizeof(int) * n); //동적할당

	pick(num, 4, bucket, n, n, money);

	free(bucket);
}