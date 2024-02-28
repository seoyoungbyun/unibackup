#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
int sum = 0;
void pick(int n, int* bucket, int m, int toPick, int l) {
    int i, lastIndex, smallest;
    int count = 0;

    lastIndex = m - toPick - 1;
    for (i = 0; i <= lastIndex; i++)
        if (bucket[i] & 1)
            count++;

    int num = (n - lastIndex) / 2;
    if (count + num < l)
        return;
    if (count + (toPick + 1) <= l)
        return;

    if (toPick == 0) {
        if (count >= l)
            sum++;
        return;
    }

    lastIndex = m - toPick - 1;
    if (m == toPick)
        smallest = 0;
    else
        smallest = bucket[lastIndex] + 1;

    for (i = smallest; i < n; i++) {
        bucket[lastIndex + 1] = i;
        pick(n, bucket, m, toPick - 1, l);
    }
}
int main(void) {
    int n, m, l;
    scanf("%d %d %d", &n, &m, &l);

    int* bucket = (int*)malloc(sizeof(int) * m);

    pick(n, bucket, m, m, l);
    printf("%d", sum);

    free(bucket);
    return 0;
}