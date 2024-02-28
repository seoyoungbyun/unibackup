#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
long f(int n, long* memo)
{
	if (n == 1 || n == 2 || n == 3)
		return 1;
	
	if (memo[n - 1] == 0)
		memo[n - 1] = f(n - 1, memo);
	if (memo[n - 2] == 0)
		memo[n - 2] = f(n - 2, memo);
	if (memo[n - 3] == 0)
		memo[n - 3] = f(n - 3, memo);

	return memo[n - 1] + memo[n - 2] + memo[n - 3];
}
int main(void) {
	int n;
	scanf("%d", &n);
	
	long* memo = (long*)malloc(sizeof(long) * (n + 1));
	for (int i = 1; i <= n; i++)
		memo[i] = 0;

	long fib = f(n, memo);
	printf("%d\n", fib);

	free(memo);
}