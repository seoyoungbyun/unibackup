#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Student
{
	int id;
	int korean, english, math;
};
void swqp(struct Student arr[], int i, int j) {
	struct Student temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
int partition(struct Student arr[], int p, int r, int num)
{
	int i, j;
	struct Student temp;

	i = p - 1;

	for (j = p; j < r; j++) {
		switch (num)
		{
			case 1:
				if (arr[j].korean > arr[r].korean)
				{
					i++;
					swqp(arr, i, j);
				}
				break;
			case 2:
				if (arr[j].math > arr[r].math) {
					i++;
					swqp(arr, i, j);
				}
				break;
			case 3:
				if (arr[j].english > arr[r].english)
				{
					i++;
					swqp(arr, i, j);
				}
				break;
			case 4:
				if (arr[j].id < arr[r].id)
				{
					i++;
					swqp(arr, i, j);
				}
				break;
			}
		}

	i++;
	temp = arr[i];
	arr[i] = arr[r];
	arr[r] = temp;

	return i;
	}
void quickSort(struct Student arr[], int p, int r, int num) {
	int q;

	if (p < r) {
		q = partition(arr, p, r, num);
		quickSort(arr, p, q - 1, num);
		quickSort(arr, q + 1, r, num);
	}
}
int main(void) {
	int n;

	printf("학생 수를 입력하세요: ");
	scanf("%d", &n);
	struct Student* std = (struct Student*)malloc(sizeof(struct Student) * n);

	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		std[i].id = (i + 1);
		std[i].korean = rand() % 101;
		std[i].english = rand() % 101;
		std[i].math = rand() % 101;
	}

	for (int i = 0; i < n; i++) {
		printf("학번:%d\t\t영어:%d\t\t수학:%d\t\t국어:%d\n", std[i].id, std[i].english, std[i].math, std[i].korean);
	}
	printf("\n");

	int choice;
	printf("정렬 기준 선택(1:국어, 2:수학, 3:영어, 4:id(오름차순), 0:끝내기): ");
	scanf("%d", &choice);
	while (choice != 0) {
		quickSort(std, 0, n - 1, choice);
		for (int i = 0; i < n; i++) {
			printf("학번:%d\t\t영어:%d\t\t수학:%d\t\t국어:%d\n", std[i].id, std[i].english, std[i].math, std[i].korean);
		}
		printf("\n");

		printf("정렬 기준 선택(1:국어, 2:수학, 3:영어, 4:id(오름차순), 0:끝내기): ");
		scanf("%d", &choice);
	}

	free(std);
}