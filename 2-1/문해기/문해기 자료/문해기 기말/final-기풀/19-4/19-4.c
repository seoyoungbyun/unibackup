#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int* item, int n, int* bucket, int m, int toPick, int total, int* diff_min) {
    int i, lastIndex, smallest;

    if (toPick == 0) {
        int sum_team_1 = 0;
        int sum_team_2 = 0;
        int diff = 0;
        for (i = 0; i < m; i++)
            sum_team_1 = sum_team_1 + item[bucket[i]];
        sum_team_2 = total - sum_team_1;

        diff = (sum_team_1 > sum_team_2) ? (sum_team_1 - sum_team_2) : (sum_team_2 - sum_team_1);

        if (*diff_min > diff) {
            *diff_min = diff;
        }
        /*
        for(i=0; i<m; i++)
            printf("%d ", bucket[i]);
        printf(" %d\n", diff);*/
        return;
    }

    lastIndex = m - toPick - 1;
    if (m == toPick)
        smallest = 0;
    else
        smallest = bucket[lastIndex] + 1;

    for (i = smallest; i < n; i++) {
        bucket[lastIndex + 1] = i;
        pick(item, n, bucket, m, toPick - 1, total, diff_min);
    }
}

int main() {
    int n, i;
    int* capacity;
    int* bucket;
    int sum = 0;
    int diff_min = 0;

    scanf("%d", &n); // bucket -> n/2

    bucket = (int*)malloc(sizeof(int) * (n / 2));
    capacity = (int*)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        scanf("%d", &capacity[i]);
        sum += capacity[i];
    }

    bucket[0] = 0;//Á¦ÀÏ ¾Õ¿¡ 0 »Ì¾Æ³õ°í ½ÃÀÛ
    diff_min = sum;
    pick(capacity, n, bucket, n / 2, n / 2 - 1, sum, &diff_min);//0 »Ì¾Æ¼­ »ÌÀ» °Å -1

    printf("%d\n", diff_min);
    return 0;
}