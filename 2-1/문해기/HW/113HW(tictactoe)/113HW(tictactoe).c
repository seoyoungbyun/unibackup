#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void display(char b[][3])
{
	printf("    0  1  2\n");
	printf("    -------\n");

	for (int i = 0; i < 3; i++) {
		printf("%d : ", i);
		for (int j = 0; j < 3; j++) {
			if (b[i][j] == 'X' || b[i][j] == 'O') {
				printf("%c  ", b[i][j]);
			}
			else{
				printf("   ");
			}
		}
		printf("\n");
	}
}
int win(char game[][3], int col, int row, char player) {
	int sum = 0;

	//가로
	for (int i = 0; i < 3; i++) {
		if (game[col][i] == player)
			sum++;
	}
	if (sum == 3)
		return 1;

	//세로
	sum = 0;
	for (int i = 0; i < 3; i++) {
		if (game[i][row] == player)
			sum++;
	}
	if (sum == 3)
		return 1;

	//대각선
	sum = 0;
	for (int i = 0; i < 3; i++) {
		if (game[i][2 - i] == player)
			sum++;
	}
	if (sum == 3)
		return 1;

	//백 대각선
	sum = 0;
	for (int i = 0; i < 3; i++) {
		if (game[i][i] == player)
			sum++;
	}
	if (sum == 3)
		return 1;

	return 0;
}
int main(void) {
	char player, game[3][3];
	int row, col, count = 0;
	char winner;

	display(game);
	
	while (count < 9)
	{
		if (count % 2 == 0)
			player = 'X';
		else
			player = 'O';

		printf("Player %c(행 열):", player);
		scanf("%d %d", &col, &row);
		
		if (game[col][row] == 'X' || game[col][row] == 'O')
			continue;

		game[col][row] = player;
		display(game);
		if (win(game, col, row, player) == 1)
		{
			winner = player;
			break;
		}
		count++;
	}

	if (count == 9)
		printf("Nobody wins!\n");
	else
		printf("Player %c wins!\n", winner);
}