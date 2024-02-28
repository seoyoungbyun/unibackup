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
	struct Student temp = arr[j];
	arr[j] = arr[j + 1];
	arr[j + 1] = temp;
}
void bubbleSort(struct Student arr[], int n, int num) {
	int i, j;

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			switch (num) {
				case 1:
					if (arr[j].korean < arr[j + 1].korean)
						swqp(arr, i, j);
					break;
				case 2:
					if (arr[j].math < arr[j + 1].math)
						swqp(arr, i, j);
					break;
				case 3:
					if (arr[j].english < arr[j + 1].english)
						swqp(arr, i, j);
					break;
				case 4:
					if (arr[j].id > arr[j + 1].id)
						swqp(arr, i, j);
					break;
			}
		}
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
		bubbleSort(std, n, choice);
		for (int i = 0; i < n; i++) {
			printf("학번:%d\t\t영어:%d\t\t수학:%d\t\t국어:%d\n", std[i].id, std[i].english, std[i].math, std[i].korean);
		}
		printf("\n");

		printf("정렬 기준 선택(1:국어, 2:수학, 3:영어, 4:id(오름차순), 0:끝내기): ");
		scanf("%d", &choice);
	}

	free(std);
}