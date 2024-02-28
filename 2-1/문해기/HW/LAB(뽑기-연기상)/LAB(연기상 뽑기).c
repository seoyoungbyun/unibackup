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
    smallest = 0;

    for (i = smallest; i < n; i++) {
        int j = 0, flag = 0;
        for (j = 0; j <= lastIndex; j++)
            if (picked[j] == i)
                flag = 1;

        if (flag == 1)
            continue;

        picked[lastIndex + 1] = i;
        pick(actors, n, picked, m, toPick - 1);
    }
}
int main(void)
{
	char* actors[] = { "공유", "김수현", "송중기", "지성", "현빈" };
	int n;
	int picked[5];

	printf("상의 종류는? ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		printf("   상 %d\t", i);
    printf("\n");

	pick(actors, 5, picked, n, n);
}