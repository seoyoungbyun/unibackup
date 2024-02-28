#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int digits(int n) {
    int num_of_digits = 0;
    while (n != 0) {
        n = n / 10;
        num_of_digits++;
    }
    return num_of_digits;
}

int kth_digit(int n, int k) {
    int i = 0;
    int ret;

    for (i = 0; i < k; i++) {
        ret = n % 10;
        n = n / 10;
    }
    return ret;
}

int solution(int n) {
    int i = 0;
    int t_digits = 0;

    while (t_digits < n) {
        i++;
        t_digits = t_digits + digits(i);
    }
    //t_digits - n + 1
    //printf("%d %d %d %d\n",t_digits, n, i, kth_digit(i,t_digits-n+1));
    return kth_digit(i, t_digits - n + 1);
}

int main() {
    int n;

    scanf("%d", &n);
    printf("%d\n", solution(n));
    //printf("%d\n", digits(n));
    return 0;
}