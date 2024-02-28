#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char ladder[101][101];
	int col, row, location;

	scanf("%d %d", &row, &col);
	scanf("%d", &location);
	for (int i = 0; i < col; i++)
		scanf("%s", ladder[i]);

	for (int i = 0; i < col; i++) {
		if (location == 0) {
			if (ladder[i][location] == '1')
				location++;
		}
		else if (location == row - 1) {
			if (ladder[i][location - 1] == '1')
				location--;
		}
		else
		{
			if (ladder[i][location] == '1')
				location++;
			else if (ladder[i][location - 1] == '1')
				location--;
		}
	}

	printf("%d\n", location);
}