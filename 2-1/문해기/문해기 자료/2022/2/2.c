//2019_2-2πÆ¡¶¿”
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int arithmetical_progression(int* number, int n) {
    int i = 0;
    int diff;
    if (n == 1)
        return 1;

    diff = number[1] - number[0];
    for (i = 0; i < n - 1; i++)
        if (number[i + 1] - number[i] != diff)
            return 0;
    return 1;
}

int pick(int items[], int n, int* picked, int m, int toPick, int* number_1, int* number_2) {
    int i, j, lastIndex, ret = 0;

    if (toPick == 0) {
        int picked_index;
        for (i = 0; i < m; i++) {
            picked_index = picked[i];
            number_2[i] = number_1[i] + items[picked_index];
            if (items[picked_index] != 0)
                ret++;
        }

        if (arithmetical_progression(number_2, m) == 1) {
            /*
            for(i=0; i<m; i++) {
                printf("%d ", number_2[i]);
            }
            printf("\n");
            */
            return ret;
        }
        return m + 1;
    }

    lastIndex = m - toPick - 1;
    ret = m + 1;

    for (i = 0; i < n; i++) {
        int pick_ret;
        picked[lastIndex + 1] = i;
        pick_ret = pick(items, n, picked, m, toPick - 1, number_1, number_2);
        if (ret > pick_ret)
            ret = pick_ret;
    }
    return ret;
}


int main() {
    int items[] = { -1, 0, 1 };
    int n, i, ret;
    int* picked, * number_1, * number_2;

    scanf("%d", &n);
    picked = (int*)malloc(sizeof(int) * n);
    number_1 = (int*)malloc(sizeof(int) * n);
    number_2 = (int*)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
        scanf("%d", &number_1[i]);

    ret = pick(items, 3, picked, n, n, number_1, number_2);
    printf("%d\n", ret == n + 1 ? -1 : ret);

    free(picked);
    free(number_1);
    free(number_2);
    return 0;
}