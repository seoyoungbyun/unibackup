#include <stdio.h>
#include <stdlib.h>
//1) typedef���� Score�� ����
typedef struct score {
	int midterm;
	int final;
}Score;
void printScore(Score* p) {
	printf("�߰���� ������ %d\n", p->midterm);
	printf("�б⸻��� ������ %d\n", p->final);
}
Score* biggerScore(Score* p1, Score* p2) {
	int i = p1->midterm + p1->final;
	int j = p2->midterm + p2->final;

	if (i > j)
		return p1;
	return p2;
}
Score* totalScore(Score* p1, Score* p2) {
	Score* total = (Score*)malloc(sizeof(Score));

	total->midterm = p1->midterm + p2->midterm;
	total->final = p1->final + p2->final;

	return total;
}
Score* createScore(int m, int f) {
	Score* p3 = (Score*)malloc(sizeof(Score));

	p3->midterm = m;
	p3->final = f;

	return p3;
}
int main(void) {
	Score s1, s2;
	Score* p3;

	s1.midterm = 50;
	s1.final = 100;
	s2.midterm = 70;
	s2.final = 70;

	printScore(&s1);
	printScore(&s2);

	printf("-----------------------------\n");
	printf("���� ������ ���� ����:\n");
	printScore(biggerScore(&s1, &s2));

	printf("-----------------------------\n");
	printf("�� ������ �� ��:\n");
	printScore(totalScore(&s1, &s2));

	printf("-----------------------------\n");
	p3 = createScore(100, 100);
	printScore(p3);
}