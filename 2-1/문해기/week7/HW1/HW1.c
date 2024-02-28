#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Student
{
	int id;
	int korean, english, math;
};
void selectionSort(struct Student arr[], int n) {
	int i, j;

	for (i = 0; i < n - 1; i++) {
		struct Student max = arr[0];
		int maxIndex = 0;

		for (j = 1; j < n - i; j++) {
			if (arr[j].korean < max.korean) {
				max = arr[j];
				maxIndex = j;
			}
		}
		
		struct Student temp = arr[n - 1 - i];
		arr[n - 1 - i] = arr[maxIndex];
		arr[maxIndex] = temp;
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

	selectionSort(std, n);
	printf("\n정렬된 정보: \n");
	for (int i = 0; i < n; i++) {
		printf("학번:%d\t\t영어:%d\t\t수학:%d\t\t국어:%d\n", std[i].id, std[i].english, std[i].math, std[i].korean);
	}

	free(std);
}