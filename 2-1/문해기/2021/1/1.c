#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void calculateReverse(char n[]) {
	int len = strlen(n);
	char middle;
	
	for (int i = 0; i < len / 2; i++)
	{
		middle = n[i];
		n[i] = n[len - i - 1];
		n[len - i - 1] = middle;
	}
}
int main(void) {
	char num1[101], num2[101];
	int carry = 0, count = 0;

	scanf("%s", num1);
	scanf("%s", num2);

	calculateReverse(num1);
	calculateReverse(num2);
	
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int i = 0, j = 0;
	while (i < len1 || j < len2) {
		int sum = ((num1[i] - '0') % 10) + ((num2[j] - '0') % 10);
		
		if (i >= len1)
			sum = (num2[j] - '0') % 10;
		else if (j >= len2)
			sum = (num1[i] - '0') % 10;

		if (sum + carry >= 10)
		{
			carry = 1;
			count++;
		}
		else
			carry = 0;

		i++;
		j++;
	}

	printf("%d\n", count);
}