#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int H(int n, int* F)
{
	int sum = 0;

	if (n == 0 || n == 1)
	{
		F[n] = 1;
		return F[n];
	}
	else {
		for (int i = 0; i < n; i++)
		{
			if (F[i] == 0)
				F[i] = H(i, F);
			if (F[n - 1 - i] == 0)
				F[n - 1 - i] = H(n - 1 - i, F);

			sum += F[i] * F[n - 1 - i];
		}

		return sum;
	}

}
int main(void)
{
	int n;
	
	printf("0보다 큰 정수: ");
	scanf("%d", &n);

	int* F = (int*)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
		F[i] = 0;
	/*F에 n + 1만큼 할당*/
	printf("결과는 %d\n", H(n, F));

	free(F);
}