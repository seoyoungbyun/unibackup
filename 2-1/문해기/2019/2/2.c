#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void isThree(char s[], int lastIndex) {
	int sum = 0;

	for (int i = 0; i < lastIndex; i++) {
		int last = s[i] - '0';
		sum += last;
	}

	if (sum == 0)
		printf("0");
	else if (sum % 3 == 0)
		printf("1");
	else
		printf("0");
}
void isFour(char s[], int lastIndex, int zero) {
	int num = (s[lastIndex - 2] - '0') * 10 + (s[lastIndex - 1] - '0');

	if (zero == 0)
		printf("0");
	else if (num % 4 == 0)
		printf("1");
	else
		printf("0");
}
int main(void)
{
	char s[52];
	int zero, lastIndex, last;

	scanf("%s", s);

	zero = s[0] - '0';
	lastIndex = strlen(s);
	last = s[lastIndex - 1] - '0';

	if (zero == 0)
		printf("0");
	else if (last % 2 == 0)
		printf("1");
	else 
		printf("0");
	
	isThree(s, lastIndex);
	
	isFour(s, lastIndex, zero);
	
	if (zero == 0)
		printf("0\n");
	else if (last % 5 == 0)
		printf("1\n");
	else
		printf("0\n");

}