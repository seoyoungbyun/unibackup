#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int num[5], i, key;

	printf("Enter 5���� ����: ");
	for (i = 0; i < 5; i++)
		scanf("%d", &num[i]);

	printf("Enter a key: ");
	scanf("%d", &key);

	for (i = 0; i < 5; i++)
		if (num[i] == key)
			break;

	if (i == 5)
		printf("����\n");
	else
		printf("%d��°�� �ִ�\n", i + 1);
}