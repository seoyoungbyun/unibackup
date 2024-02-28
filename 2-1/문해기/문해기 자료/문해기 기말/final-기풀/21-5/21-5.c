#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Coefficient {
    int F1;
    int F0;
    int flag;
};

struct Coefficient fib(int n, struct Coefficient* memo) {
    struct Coefficient ret;
    if (memo[n].flag != 0) return memo[n];
    memo[n].flag = 1;

    if (n == 0) {
        ret.F1 = 0;
        ret.F0 = 1;
        memo[n] = ret;
        return ret;
    }
    else if (n == 1) {
        ret.F1 = 1;
        ret.F0 = 0;
        memo[n] = ret;
        return ret;
    }
    else {
        struct Coefficient fn_1;
        struct Coefficient fn_2;

        fn_1 = fib(n - 1, memo);
        fn_2 = fib(n - 2, memo);

        ret.F1 = fn_1.F1 + fn_2.F1;
        ret.F0 = fn_1.F0 + fn_2.F0;
        memo[n] = ret;
        return ret;
    }

}

int main() {
    int n, i;
    struct Coefficient* memo;
    struct Coefficient ret;
    scanf("%d", &n);

    memo = (struct Coefficient*)malloc(sizeof(struct Coefficient) * (n + 1));
    for (i = 0; i < n + 1; i++) {
        memo[i].flag = 0;
    }
    ret = fib(n, memo);

    //printf("%d %d\n", ret.F1, ret.F0);
    printf("%d %d\n", memo[n].F1, memo[n].F0);
    return 0;
}