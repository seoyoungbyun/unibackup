#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
int sum = 0;
void pick(int n, int* bucket, int total, int toPick, int l) {
    int smallest, count = 0;
    int lastIndex = total - toPick - 1;

    for (int i = 0; i <= lastIndex; i++) 
        if (!(bucket[i] & 1))//bucket[i] % 2 == 1���� ��Ʈ������ &�� �ٲ���� ����->???�̰� ����� ����ȭ ����� ����
            count++; 

    int reEven = (n - lastIndex) / 2; //���� ������ ¦���� ����
    if (count + reEven < l)
        return;

    if (count + toPick < l)
        return;

    if (toPick == 0) {
        if (count >= l)
            sum++;
        
        return;
    }

    if (total == toPick)
        smallest = 1;
    else
        smallest = bucket[lastIndex] + 1;

    for (int i = smallest; i <= n; i++) {
        bucket[lastIndex + 1] = i;
        pick(n, bucket, total, toPick - 1, l);
    }
}
int main(void) {
    int n, m, l;
    
    scanf("%d %d %d", &n, &m, &l);

    int *bucket = (int*)malloc(sizeof(int) * m);

    pick(n, bucket, m, m, l);
    printf("%d\n", sum);

    free(bucket);
}