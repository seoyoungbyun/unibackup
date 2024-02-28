#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int get_cycle_number(int n)
{
	int len = 0;

	while (n != 1)
	{
		printf("%d ", n);
		if (n % 2 == 0)
			n /= 2;
		else
			n = n * 3 + 1;
		
		len++;
	}
	printf("1\n");

	return len + 1;
}
int main(void)
{
	int n, len;

	printf("Enter the number: ");
	scanf("%d", &n);

	len = get_cycle_number(n);

	printf("사이클의 길이는 %d\n", len);
}