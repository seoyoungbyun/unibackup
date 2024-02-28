#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int min = 10001;
void pick(int num[], int numSize, int* bucket, int bucketSize, int k, int n, int number) {
	int i, lastIndex, smallest, index;
	int sum = 0;
	int count = 0;

	lastIndex = bucketSize - k - 1;
	for (int i = 0; i < lastIndex + 1; i++)
	{
		//printf("%d ", num[bucket[i]]);
		sum += num[bucket[i]];
		count++;

		if (sum > number)
			return;
	}
	//printf("\n");
	if (lastIndex > min)
		return;

	if (sum == number) {
		if (count < min)
			min = count;
		return;
	}

	if (k == 0)
		return;
	
	
	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex];

	for (index = smallest; index < numSize; index++) {
		int min_ret;
		bucket[lastIndex + 1] = index;
		pick(num, numSize, bucket, bucketSize, k - 1, n, number);

		if (min == 2 || min == 1)
			break;
	}
	return min;
}
int main(void) {
	int i, n;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		if (n < i * i)
			break;
	}
	i--;
	int numSize = i;

	int* bucket = (int*)malloc(sizeof(int) * n); //동적할당
	int* num = (int*)malloc(sizeof(int) * i);

	for (int j = 0; j < numSize; j++) {
		num[j] = i * i;
		i--;
	}

	pick(num, numSize, bucket, numSize, numSize, numSize, n);

	printf("%d\n", min);

	free(bucket);
	free(num);
}

