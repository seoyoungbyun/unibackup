#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int H(int n) {
    if (n == 0 || n == 1)
        return 1;
    else {
        int sum = 0;
        
        for (int i = 0; i < n; i++)
            sum = sum + H(i) * H(n - i - 1);
        
        return sum;
    }
}

int main(void) {
    int n;
    
    printf("Enter the number: ");
    scanf("%d", &n);

    printf("%d\n", H(n));
}