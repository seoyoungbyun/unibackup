#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int calDigits(int n)
{
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

int main(void)
{
    int n;
    int num = 0;
    int jarisu;
    scanf("%d", &n);

    while (n > 0) {
        num += 3;
        jarisu = calDigits(num);
        if (n <= jarisu) {
            printf("%d %d\n", num, n);
            for (int i = 0; i < (jarisu - n); i++)
                num = num / 10;
            printf("%d\n", num % 10);
        }
        n = n - jarisu;
    }
    return 0;
}