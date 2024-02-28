#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void pick(char item[], int n, int* bucket, int bucketSize, int k) {
	int i, lastIndex, smallest, index;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%c ", item[bucket[i]]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;

	for (index = smallest; index < n; index++) {
		bucket[lastIndex + 1] = index;
		pick(item, n, bucket, bucketSize, k - 1);
	}
}
int main(void) {
	char item[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
	int n = 7;
	int bucket[3];

	pick(item, n, bucket, 3, 3);
}