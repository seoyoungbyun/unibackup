#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int count(int a[], int n, int k) {
	int c = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] / 10 > 0) {
			while (a[i] > 0) {
				int middle = a[i] % 10;
				if (middle == k) {
					c++;
				}
				a[i] /= 10;
			}
		}
		else {
			if (a[i] == k)
				c++;
		}
	}

	return c;
}
int main(void) {
	int n, k;
	int a[1000];

	scanf("%d", &n);
	scanf("%d", &k);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int num = count(a, n, k);

	printf("%d", num);
}