typedef struct student {
	char name[20];
	int midterm;
	int final;
}Student;
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	Student *sp = (Student*)malloc(sizeof(Student));
	
	printf("Enter student name: ");
	scanf("%s", sp->name);
	printf("Enter midterm and final score: ");
	scanf("%d %d", &sp->midterm, &sp->final);
	
	printf("\n�̸�\t�߰�\t�б⸻\n");
	printf("%s\t%d\t%d\n", sp->name, sp->midterm, sp->final);

	free(sp);
}