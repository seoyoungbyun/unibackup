#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Student
{
	int id;
	int korean, english, math;
};
void bubbleSortDescendingByKorean(struct Student arr[], int n) {
	int i, j;

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (arr[j].korean < arr[j + 1].korean)
			{
				struct Student temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void bubbleSortAscendingById(struct Student arr[], int n) {
	int i, j;

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (arr[j].id > arr[j + 1].id)
			{
				struct Student temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main(void) {
	int n;

	printf("Enter a number: ");
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

	bubbleSortDescendingByKorean(std, n);
	printf("\n국어 성적으로 내림차순 정렬된 정보: \n");
	for (int i = 0; i < n; i++) {
		printf("학번:%d\t\t영어:%d\t\t수학:%d\t\t국어:%d\n", std[i].id, std[i].english, std[i].math, std[i].korean);
	}

	bubbleSortAscendingById(std, n);
	printf("\nid로 오름차순 정렬된 정보: \n");
	for (int i = 0; i < n; i++) {
		printf("학번:%d\t\t영어:%d\t\t수학:%d\t\t국어:%d\n", std[i].id, std[i].english, std[i].math, std[i].korean);
	}

	free(std);
}