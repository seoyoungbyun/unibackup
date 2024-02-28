#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int* item, int n, int* bucket, int m, int toPick, int target, int* min) {
    int i, lastIndex, smallest;
    int sum = 0;

    lastIndex = m - toPick - 1;
    for (i = 0; i <= lastIndex; i++)
        sum = sum + item[bucket[i]] * item[bucket[i]];

    if ((lastIndex + 1) > *min)
        return;

    if (sum == target) {
        if (*min > (lastIndex + 1))
            *min = lastIndex + 1;
        return;
    }

    if (sum > target)
        return;

    if (toPick == 0)
        return;

    if (m == toPick)
        smallest = 0;
    else
        smallest = bucket[lastIndex];

    for (i = smallest; i < n; i++) {
        bucket[lastIndex + 1] = i;
        pick(item, n, bucket, m, toPick - 1, target, min);
    }
}

int main() {
    int n;
    int* item;
    int* bucket;
    int min = 0;
    int i = 0;

    scanf("%d", &n);

    bucket = (int*)malloc(sizeof(int) * n);
    item = (int*)malloc(sizeof(int) * (n - 1));

    for (i = n - 2; i >= 1; i--)
        item[i] = i;

    min = n;
    pick(item, n - 1, bucket, n, n, n, &min);

    printf("%d\n", min);

    return 0;
}