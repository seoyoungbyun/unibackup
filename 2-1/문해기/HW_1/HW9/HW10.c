#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int isSame(int arr1[], int arr2[], int size)
{
	for (int i = 0; i < size; i++)
		if (arr1[i] != arr2[i])
			return 1;
	return 0;
}
int main(void)
{
	int i, arr1[5], arr2[5];

	printf("Enter ù��° �迭: ");
	for (i = 0; i < 5; i++)
		scanf("%d", &arr1[i]);
	printf("Enter �ι�° �迭: ");
	for (i = 0; i < 5; i++)
		scanf("%d", &arr2[i]);

	if (isSame(arr1, arr2, 5))
		printf("�� ���� �迭�� �ٸ���\n");
	else
		printf("�� ���� �迭�� ����\n");
}