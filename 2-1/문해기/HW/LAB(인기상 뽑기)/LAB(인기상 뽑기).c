#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void pick(char* actors[], int n, int* picked, int m, int toPick) {
    int lastIndex, smallest, i;

    if (toPick == 0) {
        for (i = 0; i < m; i++)
            printf("%6s\t ", actors[picked[i]]);
        
        printf("\n");
        return;
    }

    lastIndex = m - toPick - 1;
    
    if (toPick == m)
        smallest = 0;
    else
        smallest = picked[lastIndex] + 1;

    for (i = smallest; i < n; i++) {
        picked[lastIndex + 1] = i;
        pick(actors, n, picked, m, toPick - 1);
    }
}
int main() {
    char* actors[] = { "공유", "김수현", "송중기", "지성", "현빈" };
    int n;
    int picked[5];

    printf("인기상 몇명? ");
    scanf("%d", &n);

    pick(actors, 5, picked, n, n);

    return 0;
}