#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int pick(int n, int* picked, int m, int k)
{
	int i, lastIndex, smallest, sum = 0, answer;
	int count = 0;

	lastIndex = m - k - 1;

	for (i = 0; i <= lastIndex; i++) {
		printf("%d ", picked[i]);
		sum += picked[i] * picked[i];
		if (picked[i] != 0)
		{

			count++;
		}
		if (sum > n)
			break;
	}
	printf("\n");
	if (sum == n) {
		return count;
	}
	if (k == 0) {
		return 0;
	}


	if (m == k) {
		smallest = 0;
	}
	else {
		smallest = picked[lastIndex];
	}

	for (i = smallest; i <= m; i++) {
		picked[lastIndex + 1] = i;
		answer = pick(n, picked, m, k - 1);
		if (answer != 0) {
			return answer;
		}
	}
	return answer;
}
int main(void)
{
	int n, num = 1;

	scanf("%d", &n);

	while (1) {
		if (num * num > n) {
			break;
		}
		else {
			num++;
		}
	}
	num++;

	int* picked = (int*)malloc(sizeof(int) * num);

	printf("%d", pick(n, picked, num, num));

	free(picked);
}