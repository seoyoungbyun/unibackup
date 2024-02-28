#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int pick(int a[], int n, int* picked, int m, int toPick) {
    //char items[3] = {'+', '-', '*'};
    int i, j, lastIndex, sum = 0, max;

    if (toPick == 0) {
        for (i = 0; i < m; i++)
        {
            if (picked[i] == 0)
                sum += a[i];
            else if (picked[i] == 1)
                sum -= a[i];
            else 
                sum *= a[i];
        }

        return sum;
    }

    lastIndex = m - toPick - 1;
    max = -1;

    for (i = 0; i < 3; i++) {
        int max_ret;
        picked[lastIndex + 1] = i;
        max_ret = pick(a, n, picked, m, toPick - 1);
        if (max < max_ret)
            max = max_ret;
    }
    return max;
}
int main() {
    int n, i, sum;
    int* picked, *a;

    scanf("%d", &n);
    picked = (int*)malloc(sizeof(int) * n);
    a = (int*)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sum = pick(a, n, picked, n, n);
    printf("%d\n", sum);

    free(picked);
    free(a);
    return 0;
}