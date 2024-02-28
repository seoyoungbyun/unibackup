#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char s[81], character;
	int i, count = 0;

	printf("Enter a String: ");
	scanf("%s", s);
	getchar();
	printf("Enter a character: ");
	scanf("%c", &character);

	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == character)
			count++;

	printf("\'%c\' is appeared %d times\n", character, count);
}