#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int mul(int n)
{
    if (n == 0)
        return 1;
    
    int ans = 1;

    for (int i = 0; i < n; i++)
        ans *= 10;

    return ans;
}
int partition(char arr[], int p, int r) {
    int i, j;
    int temp;

    i = p - 1;

    for (j = p; j < r; j++) {
        if (arr[j] < arr[r]) {
            i++;
            //arr[i] <-> arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    i++;
    temp = arr[i];
    arr[i] = arr[r];
    arr[r] = temp;


    return i;
}

void quickSort(char arr[], int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

int main(void) {
    char s[9];
    char s2[9];
    int sum = 0;

    int Y[5] = { 0 };
    int K[5] = { 0 };
    
    int *X = (int*)malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++)
        X[i] = 0;
    
    scanf("%s", s);
    scanf("%s", s2);
    
    int len = strlen(s);
    int len2 = strlen(s2);
    
    for (int i = 0; i < len; i++)
        s[i] -= 65;
    for (int i = 0; i < len2; i++)
        s2[i] -= 65;
    
    for (int i = 0; i < len; i++) {
        X[s[i]] += mul(len - i - 1);
    }
    for (int i = 0; i < len2; i++) {
        X[s2[i]] += mul(len2 - i - 1);
    }
    for (int i = 0; i < 5; i++)
        K[i] = X[i];
    quickSort(X, 0, 4, len);

    for (int i = 0; i < 5; i++) 
        for (int j = 0; j < 5; j++) 
            if (X[i] == K[j]) {
                Y[j] = i + 1;
                K[j] = -1;
                break;
            }

    for (int i = 0; i < len; i++) 
        sum += Y[s[i]] * mul(len - 1 - i);

    for (int i = 0; i < len2; i++) 
        sum += Y[s2[i]] * mul(len2 - 1 - i);
    
    printf("%d", sum);
    free(X);
}