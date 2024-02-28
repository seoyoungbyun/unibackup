#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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
int main(void) {
    int n;
    int arr[100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int output = arithmetical_progression(arr, n);

    printf("%d\n", output);
}