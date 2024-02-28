#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int comb(int n, int r, int **F)
{
	//printf("comb(%d, %d)\m", n, r);
	if (r == 0 || n == r)
	{
		F[n][r] = 1;
		return F[n][r];
	}
	else {
		if (F[n - 1][r - 1] == 0)
			F[n - 1][r - 1] = comb(n - 1, r - 1, F);
		
		if (F[n - 1][r] == 0)
			F[n - 1][r] = comb(n - 1, r, F);

		F[n][r] = F[n - 1][r - 1] + F[n - 1][r];
		
		return F[n][r];
	}
}
int main(void)
{
	int C;
	int n, r;
	int** F;

	printf("Enter n and r: ");
	scanf("%d %d", &n, &r);

	F = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 0; i < n + 1; i++)
		F[i] = (int*)malloc(sizeof(int*) * (r + 1));

	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < r + 1; j++)
			F[i][j] = 0;

	C = comb(n, r, F);
	printf("%d\n", C);

	for (int i = 0; i < n + 1; i++)
		free(F[i]);
	free(F);

	return 0;
}