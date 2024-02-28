#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mul(int n)
{
    if (n == 0)
        return 1;

    int num = 1;
    for (int i = 0; i < n; i++)
        num *= 10;

    return num;
}
int pick(int n, int* bucket, int total, int toPick, char s[], int len, char s2[], int len2) {
    int i, lastIndex, smallest;
    int max = 0;

    if (toPick == 0) {
        /*for (int i = 0; i < 5; i++)
            printf("%d ", bucket[i]);
        printf("\n");*/

        int sum = 0;

        for (int i = 0; i < len; i++)
            sum += mul(len - 1 - i) * bucket[s[i]];

        for (int i = 0; i < len2; i++)
            sum += mul(len2 - 1 - i) * bucket[s2[i]];

        return sum;
    }

    lastIndex = total - toPick - 1;
    smallest = 1;

    for (i = smallest; i < n + 1; i++) {
        int flag = 0;
        for (int j = 0; j <= lastIndex; j++)
            if (bucket[j] == i)
                flag = 1;
        if (flag == 1)
            continue;

        bucket[lastIndex + 1] = i;
        int sum = pick(n, bucket, total, toPick - 1, s, len, s2, len2);
        
        if (sum > max) 
            max = sum;
    }

    return max;
}
int main(void) {
    char s[9];
    char s2[9];

    scanf("%s", s);
    scanf("%s", s2);

    int len = strlen(s);
    int len2 = strlen(s2);

    for (int i = 0; i < len; i++)
        s[i] -= 'A';
    for (int i = 0; i < len2; i++)
        s2[i] -= 'A';

    int bucket[5];

    int sum = pick(5, bucket, 5, 5, s, len, s2, len2);

    printf("%d\n", sum);
}