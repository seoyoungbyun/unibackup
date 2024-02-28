#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int get_cycle_number(int n)
{
	if (n == 1)
	{
		printf("%d\n", n);
		return 1;
	}
	else if (n % 2 == 0)
	{
		printf("%d ", n);
		return 1 + get_cycle_number(n / 2);
	}
	else
	{
		printf("%d ", n);
		return 1 + get_cycle_number(n * 3 + 1);
	}
}
int main(void)
{
	int n, len;

	printf("Enter the number: ");
	scanf("%d", &n);

	len = get_cycle_number(n);

	printf("사이클의 길이는 %d\n", len);
}