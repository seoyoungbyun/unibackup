#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void print(void)
{
	printf("*** 로또 번호 생성기 ***\n");
	printf("생성 번호: ");

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
		
		printf("\n다시 생성하겠습니까? (y/n): ");
		scanf("%c", &again);

		if (again == 'n')
			break;
		
		getchar();
	}
}