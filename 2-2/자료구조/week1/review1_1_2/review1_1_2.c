#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h> 
void reverse_string(char* str, int s, int e)
{
	// 작성할 것 
	for (int i = s; i <= e / 2; i++) {
		int tmp = str[i];
		str[i] = str[e - i];
		str[e - i] = tmp;
	}
}

int main()
{
	char str[100];

	printf("Enter any string:");
	scanf("%s", str);

	reverse_string(str, 0, strlen(str) - 1);
	printf("\nReversed String is: %s", str);
	return 0;
}