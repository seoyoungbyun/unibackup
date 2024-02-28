#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n, i, mul = 1;

	printf("Enter a number: ");
	scanf("%d", &n);

	i = 0;
	while (i < n)
	{
		mul *= 2;
		i++;
	}

	printf("%d\n", mul);
}