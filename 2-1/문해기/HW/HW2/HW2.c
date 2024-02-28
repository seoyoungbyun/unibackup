#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(char *op, int n, int* bucket, int bucketSize, int k) {
	int i, lastIndex, smallest, index;
	int sum = 0;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
		{
			printf("%c", op[bucket[i]]);
			printf("%d", (i + 1));
			if (bucket[i] == 0)
				sum += i + 1;
			else
				sum += -i - 1;
		}
		printf(" = %d\n", sum);

		return;
	}

	lastIndex = bucketSize - k - 1;

	for (index = 0; index < n; index++) {
		bucket[lastIndex + 1] = index;
		pick(op, n, bucket, bucketSize, k - 1);
	}
}
int main(void) {
	char op[] = { '+', '-' };
	int n;

	printf("입력: ");
	scanf("%d", &n);

	int* bucket = (int*)malloc(sizeof(int) * n); //동적할당

	pick(op, 2, bucket, n, n);

	free(bucket);
}