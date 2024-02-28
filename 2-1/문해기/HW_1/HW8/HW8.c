#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void input(char name[])
{
	printf("Enter your name: ");
	scanf("%s", name);
}
void reverse(char name[])
{
	char rename[sizeof(name) / sizeof(char)];
	int i;
	int size = sizeof(name) / sizeof(char) - 1;

	for (i = size; i > 0; i--)
		rename[size - i] = name[i - 1];
	
	rename[size] = '\0';

	printf("Reverse: %s\n", rename);
}
int main(void)
{
	char name[81];

	input(name);
	reverse(name);
}