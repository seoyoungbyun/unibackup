#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	int a, num = 1;
	unsigned long long c = 1;

	scanf("%d", &a);

	while (c % a != 0) {
		c = c * 10 + 1;
		num++;
	}

	printf("%d\n", num);
}