#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int fib0(int n, int* F)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 0;
	
	if (F[n - 1] == -1)
		F[n - 1] = fib0(n - 1, F);
	
	if (F[n - 2] == -1)
		F[n - 2] = fib0(n - 2, F);

	return F[n - 1] + F[n - 2];
}
int fib1(int n, int* F)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	
	if (F[n - 1] == -1)
		F[n - 1] = fib1(n - 1, F);
	
	if (F[n - 2] == -1)
		F[n - 2] = fib1(n - 2, F);

	return F[n - 1] + F[n - 2];
}
int main(void) {
	int n;

	scanf("%d", &n);

	int* F0 = (int*)malloc(sizeof(int) * n);
	int* F1 = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		F0[i] = -1;
		F1[i] = -1;
	}

	printf("%d %d\n", fib1(n, F1), fib0(n, F0));
	free(F1);
	free(F0);
}
/*
int n[46];
int fib1(int num) {
	n[0] = 0;
	n[1] = 1;

	for (int i = 2; i <= num; i++)
		n[i] = n[i - 1] + n[i - 2];

	return n[num];
}
int fib0(int num) {
	n[0] = 1;
	n[1] = 0;

	for (int i = 2; i <= num; i++)
		n[i] = n[i - 1] + n[i - 2];

	return n[num];
}*/