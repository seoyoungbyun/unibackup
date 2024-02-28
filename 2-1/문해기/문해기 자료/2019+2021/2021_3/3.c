#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int toNum(char ch)
{
	if (ch == '\0')
		return 0;
	else
		return ch - '0';
}
int carry(char n1[], char n2[], char result[])
{
	int i, carry = 0, carryCount = 0;
	int sum;
	for (i = 0; n1[i] != '\0' || n2[i] != '\0'; i++) {
		sum = toNum(n1[i]) + toNum(n2[i]) + carry;
		result[i] = sum % 10 + '0';
		if (sum >= 10) {
			carry = 1;
			carryCount++;
		}
		else {
			carry = 0;
		}
	}
	if (carry == 1) result[i++] = 1 + '0';
	result[i] = '\0';
	return carryCount;
}

void reverse(char src_n[], char n[])
{
	int len = strlen(src_n);
	int i;
	for (i = 0; src_n[i] != '\0'; i++)
		n[len - i - 1] = src_n[i];
	n[len] = '\0';
}


int main(void)
{
	char src_num1[101];
	char src_num2[101];
	char result[101];
	char result2[101];
	char num1[101] = { 0 };
	char num2[101] = { 0 };

	scanf("%s %s", src_num1, src_num2);
	reverse(src_num1, num1);
	reverse(src_num2, num2);

	printf("%d\n", carry(num1, num2, result));
	return 0;
}