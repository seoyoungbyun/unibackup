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
void pick(int a[], int b[], int na, int nb, int m, int toPick, int picked[]) {
    int i, j, lastIndex, sum = 0;
    int copy[100];

    if (toPick == 0) {
        for (int i = 0; i < nb; i++)
            copy[i] = b[i];
        
        for (int i = 0; i < na; i++) {
            b[picked[i]] = a[i];
        }
        if (arithmetical_progression(b, nb) == 1) {
            return;
        }
        else {
            for (int i = 0; i < nb; i++)
                b[i] = copy[i];
        }
    }

    lastIndex = m - toPick - 1;

    for (i = 0; i < nb; i++) {
        int j = 0, flag = 0;
        
        for (j = 0; j < lastIndex; j++)
            if (picked[j] == i)
                flag = 1;
        if (flag == 1)
            continue;
        
        picked[lastIndex + 1] = i;
        pick(a, b, na, nb, m, toPick - 1, picked);
    }
}
int main() {
    int na, nb;
    int a[100], b[100], picked[100];

    scanf("%d", &na);
    for (int i = 0; i < na; i++)
        scanf("%d", &a[i]);
    scanf("%d", &nb);
    for (int i = 0; i < nb; i++)
        scanf("%d", &b[i]);

    pick(a, b, na, nb, na, na, picked);
    
    int sum = 0;
    if (arithmetical_progression(b, nb) == 1) {
        for (int i = 0; i < nb; i++) {
            sum += b[i];
        }
        printf("%d", sum);
    }
    else
        printf("%d", -1);

    return 0;
}