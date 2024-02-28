#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int calculateReverse(long long n)
{
    long long reverse = 0;

    while (n != 0) {
        reverse = (reverse * 10) + (n % 10);
        n /= 10;
    }

    return reverse;
}
int main(void)
{
    long long n, reverse;
    int count = 0;

    scanf("%lld", &n);

    reverse = calculateReverse(n);

    while (reverse != n) {
        count++;
        n += reverse;
        reverse = calculateReverse(n);

        if (count > 1000) {
            printf("NaN\n");
            return;
        }
    }

    printf("%d %lld\n", count, n);
}