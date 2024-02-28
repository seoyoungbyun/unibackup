#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void printN(int n) {
	if (n == 0)
		return;
	else {
		printN(n / 10);
		printf("%d ", n % 10);
	}
}
int main(void)
{
	int n;

	scanf("%d", &n);
	n *= 9;
	
	if (n == 0)
		printf("0");
	else
		printN(n);

	printf("\n");
}