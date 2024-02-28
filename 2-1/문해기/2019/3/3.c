#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int solution(int n)
{
	int count = 0;
	
	while (n > 0){
		n /= 10;
		count++;
	}

	return count;
}
int main(void) {
	int i, n, count = 0;

	scanf("%d", &n);

	i = 1;
	while (n > count) {
		count += solution(3 * i);
		i++;
	}

	int num = 3 * (i - 1);
	for (int j = 0; j < count - n; j++) {
		num /= 10;
	}

	printf("%d\n", num % 10);
}