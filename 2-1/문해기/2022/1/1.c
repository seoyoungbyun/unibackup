#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void change(char s[], int num, int ch, int index) {
	if (num == 0)
	{
		s[index] = '\0';
		return;
	}
	else {
		change(s, num / ch, ch, index + 1);
		s[index] = num % ch + 'A';
	}
}
int isPalindrome(char s[]) {
	for (int i = 0; i < strlen(s) / 2; i++)
		if (s[i] != s[strlen(s) - i - 1])
			return 0;
	return 1;
}
int main(void) {
	int num, ch;
	char s[30];

	scanf("%d %d", &num, &ch);

	change(s, num, ch, 0);

	printf("%d\n", isPalindrome(s));
}