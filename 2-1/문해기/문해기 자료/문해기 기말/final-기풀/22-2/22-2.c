#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int* item, int n, int* bucket, int m, int toPick, int target, int* count) {
    int i, lastIndex, smallest;
    int sum = 0;

    lastIndex = m - toPick - 1;
    for (i = 0; i <= lastIndex; i++)
        sum = sum + item[bucket[i]];

    if (sum == target) {
        *count = *count + 1;
        for (i = 0; i <= lastIndex; i++)
            printf("%d ", bucket[i]);
        printf("\n");
        return;
    }

    if (sum > target)
        return;

    if (toPick == 0)
        return;

    /*
    if(toPick==0) {
        for(i=0; i<m; i++)
            printf("%d ", bucket[i]);
        printf("\n");
        return;
    }*/

    if (m == toPick)
        smallest = 0;
    else
        smallest = bucket[lastIndex];

    for (i = smallest; i < n; i++) {
        bucket[lastIndex + 1] = i;
        pick(item, n, bucket, m, toPick - 1, target, count);
    }
}

int main() {
    int n;
    int item[] = { 1,2,3 };
    int* bucket;
    int count = 0;

    scanf("%d", &n);

    bucket = (int*)malloc(sizeof(int) * n);

    pick(item, 3, bucket, n, n, n, &count);

    printf("%d\n", count);

    return 0;
}