//조합
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int try = 0;
int comb(int n, int r, int** F)
{
	//printf("comb(%d, %d)\m", n, r);
	if (r == 0 || n == r)
	{
		F[n][r] = 1;
		return F[n][r];
	}
	else {
		if (F[n - 1][r - 1] == 0)
			F[n - 1][r - 1] = comb(n - 1, r - 1, F);

		if (F[n - 1][r] == 0)
			F[n - 1][r] = comb(n - 1, r, F);

		F[n][r] = F[n - 1][r - 1] + F[n - 1][r];

		return F[n][r];
	}
}
int pick(int *item, int n, int* bucket, int bucketSize, int k, int sum, int count) {
	int lastIndex, smallest, sum1 = 0;
	int min = INT_MAX;
	
	if (try > count)
		return min;

	if (k == 0) {
		for (int i = 0; i < bucketSize; i++)
			sum1 += item[bucket[i]];
		try++;
		return sum - 2 * sum1;
	}
	lastIndex = bucketSize - k - 1;

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;

	for (int i = smallest; i < n; i++) {
		int diff;
		bucket[lastIndex + 1] = i;
		diff = pick(item, n, bucket, bucketSize, k - 1, sum, count);
		if (diff < 0)
			diff *= -1;

		if (min > diff) {
			min = diff;
		}
	}

	return min;
}
int main(void) {
	int n, num;

	scanf("%d", &n);
	num = n / 2;

	int* item = (int*)malloc(sizeof(int) * n);
	int* bucket = (int*)malloc(sizeof(int) * num);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &item[i]);
		sum += item[i];
	}

	int k = n;
	int r = num;

	int **F = (int**)malloc(sizeof(int*) * (k + 1));
	for (int i = 0; i < k + 1; i++)
		F[i] = (int*)malloc(sizeof(int*) * (r + 1));

	for (int i = 0; i < k + 1; i++)
		for (int j = 0; j < r + 1; j++)
			F[i][j] = 0;
	//조합 수 구해서 / 2
	int C = comb(k, r, F);
	C /= 2;

	int min = pick(item, n, bucket, num, num, sum, C);
	printf("%d\n", min);

	free(item);
	free(bucket);

	for (int i = 0; i < k + 1; i++)
		free(F[i]);
	free(F);
}