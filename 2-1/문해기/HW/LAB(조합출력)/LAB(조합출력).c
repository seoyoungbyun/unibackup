#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void pick(int n, int totalpick, int picked[], int willpick) {//totalpick=뽑아야 할 총 개수 willpick = 앞으로 뽑아야 할 수
	int small, lastIndex;

	if (willpick == 0) {
		for (int i = 0; i < totalpick; i++)
			printf("%d ", picked[i]);
		printf("\n");
		return;
	}

	lastIndex = totalpick - willpick - 1;

	if (totalpick == willpick)
		small = 0;
	else
		small = picked[lastIndex] + 1;

	for (int i = small; i < n; i++) {
		picked[lastIndex + 1] = i;
		pick(n, totalpick, picked, willpick - 1);
	}
}
int main() {
	int picked[4];
	pick(7, 4, picked, 4);
}