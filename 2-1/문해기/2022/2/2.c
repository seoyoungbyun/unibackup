#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int num[], int n, int* bucket, int bucketSize, int k, int count) {
	int i, lastIndex, smallest, index;

	if (k == 0) {
		for (int j =0; j < bucketSize; j++)
			if (bucket[j] != 0)
				count++;

		for (i = 0; i < bucketSize; i++)
		{
			if (bucket[i] == 1)
				num[i] += 1;
			else if (bucket[i] == 2)
				num[i] -= 1;
		}

		if (isSame(num, bucketSize) == 1) {
			printf("%d\n", count);
			
			exit(0);
		}
		else
			for (i = 0; i < bucketSize; i++)
			{
				if (bucket[i] == 1)
					num[i] -= 1;
				else if (bucket[i] == 2)
					num[i] += 1;
			}

		return;
	}

	lastIndex = bucketSize - k - 1;

	int check = 0;
	int check_num = 1;
	for (int j = 0; j < bucketSize; j++)
		check_num *= n;
	
	for (index = 0; index < n; index++) {
		check++;
		bucket[lastIndex + 1] = index;
		pick(num, n, bucket, bucketSize, k - 1, count);

		if (check == check_num)
		{
			printf("-1\n");
			exit(0);
		}
	}
}
int isSame(int num[], int size) {
	int d = num[1] - num[0];

	for (int i = 0; i < size - 1; i++)
		if (d != num[i + 1] - num[i])
			return -1;

	return 1;
}
int main(void) {
	//char op[] = {'0', '+', '-'};
	int n;

	scanf("%d", &n);

	int count = n;
	int* bucket = (int*)malloc(sizeof(int) * n); //¿¬»êÀÚ »Ì±â
	int* num = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	pick(num, 3, bucket, n, n, 0);

	if (isSame(num, n) != 1)
		printf("-1\n");

	free(bucket);
	free(num);
}