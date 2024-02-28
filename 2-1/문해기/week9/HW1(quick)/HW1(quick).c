#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Student
{
	int id;
	int korean, english, math;
};
int partition(struct Student arr[], int p, int r)
{
	int i, j;
	struct Student temp;

	i = p - 1;

	for (j = p; j < r; j++) {
		if (arr[j].korean > arr[r].korean) {
			i++;
			//arr[i] <-> arr[j]
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	i++;
	temp = arr[i];
	arr[i] = arr[r];
	arr[r] = temp;

	return i;
}
void quickSort(struct Student arr[], int p, int r) {
	int q;

	if (p < r) {
		q = partition(arr, p, r);
		quickSort(arr, p, q - 1);
		quickSort(arr, q + 1, r);
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

	quickSort(std, 0, n - 1);
	printf("\n국어 성적으로 내림차순 정렬된 정보: \n");
	for (int i = 0; i < n; i++) {
		printf("학번:%d\t\t영어:%d\t\t수학:%d\t\t국어:%d\n", std[i].id, std[i].english, std[i].math, std[i].korean);
	}

	free(std);
}