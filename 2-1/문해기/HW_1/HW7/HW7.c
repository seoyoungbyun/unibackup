#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void echo(int arr[]) {
	int num;

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &num);
		arr[i] = num;
	}
}
void reverse(int *arr)
{
	int i;

	for (i = 4; i >= 0; i--)
		printf("%d ", arr[i]);
	printf("\n");
}
int main(void)
{
	int arr[5], i;

	echo(arr);
	for (i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n");
	reverse(arr);
}