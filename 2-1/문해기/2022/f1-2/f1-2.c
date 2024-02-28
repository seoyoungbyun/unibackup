#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	int n, num, count = 0;

	scanf("%d", &n);

	int i;
	for (i = 1; count < n; i++) {
		int j = i;
		while (j > 0) {
			j /= 10;
			count++;
		}
	}
	i--;

	if (count > n)
	{
		for (int j = 0; j < count - n; j++)
			i /= 10;
	}

	num = i % 10;
	printf("%d\n", num);
}