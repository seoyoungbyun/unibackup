#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void print(void)
{
	printf("*** �ζ� ��ȣ ������ ***\n");
	printf("���� ��ȣ: ");

	for (int i = 0; i < 6; i++)
		printf("%d ", rand() % 45 + 1);
}
int main(void)
{
	char again;

	srand(time(NULL));
	while (1)
	{
		print();
		
		printf("\n�ٽ� �����ϰڽ��ϱ�? (y/n): ");
		scanf("%c", &again);

		if (again == 'n')
			break;
		
		getchar();
	}
}