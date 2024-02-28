#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//5¹øÀÌ´Ù
void change(int a[], int n, int b[], int k) {
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			if (a[j] == b[i]) {
				if (j == 0)
					break;
				else {
					int tmp = a[j];
					a[j] = a[j - 1];
					a[j - 1] = tmp;
				}
			}
		}
	}
}
int main(void) {
	int n, k, l;
	int a[1000], b[1000];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		a[i] = i;

	scanf("%d", &k);
	scanf("%d", &l);

	for (int i = 0; i < k; i++)
		scanf("%d", &b[i]);

	change(a, n, b, k);

	printf("%d", a[l]);
}