#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int partition(char s[], int p, int r) {
    int i, j;
    int temp;

    i = p - 1;

    for (j = p; j < r; j++) {
        if (s[j] < s[r]) {
            i++;
            //arr[i] <-> arr[j]
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }

    i++;
    temp = s[i];
    s[i] = s[r];
    s[r] = temp;


    return i;
}
void quickSort(char s[], int p, int r) {
    if (p < r) {
        int q = partition(s, p, r);
        quickSort(s, p, q - 1);
        quickSort(s, q + 1, r);
    }
}
int main(void) {
    char s[500001];

    scanf("%s", s);

    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        if (s[i] >= '0' && s[i] <= '9')
            s[i] += 'A';
        else
            s[i] -= '0';
    }
    quickSort(s, 0, len - 1);


    for (int i = 0; i < len; i++) {
        if (s[i] <= 'z' - '0')
            s[i] += '0';
        else
            s[i] -= 'A';
    }

    printf("%s\n", s);
}