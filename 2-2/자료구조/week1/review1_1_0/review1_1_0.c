#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h> 
void print_reverse(char *str, int end) 
{
	printf("%c", str[end]);

	if (end == 0)
	{
		printf("\n");
		return;
	}
	else
		print_reverse(str, end - 1);
	/*
	uf (end > 0)
		printf("%c", str[end])
		print_reverse(str, end - 1);
	
		printf("\n");*/
} 
int main() 
{ 
	char str[100];
	
	printf("Enter any string:"); 
	scanf("%s", str); 
	
	printf("Reversed String is: "); 
	print_reverse(str, strlen(str) - 1); // str�� ������ �ε����� �Ű������� 
	return 0; 
} 