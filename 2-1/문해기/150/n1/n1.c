#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	int num1, num2;
	int carry = 0, count = 0;

	scanf("%d %d", &num1, &num2);

	while (num1 != 0 || num2 != 0) {
		int sum = (num1 % 10) + (num2 % 10);

		if (sum + carry >= 10)
		{
			carry = 1;
			count++;
		}
		else
			carry = 0;

		num1 /= 10;
		num2 /= 10;
	}

	printf("%d\n", count);
}