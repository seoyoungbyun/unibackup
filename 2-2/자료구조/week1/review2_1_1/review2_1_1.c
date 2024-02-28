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
	//����ü ������ ���� �� ���������� ����ǹǷ� �����Ҵ����� �����ϴ� ���� �ʿ�
	Score* total = (Score*)malloc(sizeof(Score));//free�� ���?

	total->midterm = p1->midterm + p2->midterm;
	total->final = p1->final + p2->final;

	return total;
}
Score* createScore(int m, int f) {
	Score* p3 = (Score*)malloc(sizeof(Score));

	//if (p3 != NULL)
	p3->midterm = m;
	p3->final = f;

	return p3;
}
int main(void) {
	Score *p1, *p2, *p3;
	//1) p1, p2�� ���� �޸� �Ҵ��� �� ��
	p1 = (Score*)malloc(sizeof(Score));
	p2 = (Score*)malloc(sizeof(Score));
	// ����Ű�� ������ �� ����
	p1->midterm = 50;
	p1->final = 100;
	p2->midterm = 70;
	p2->final = 70;

	printScore(p1);
	printScore(p2);
	
	printf("-----------------------------\n");
	printf("���� ������ ���� ����:\n");
	printScore(biggerScore(p1, p2));
	
	printf("-----------------------------\n");
	printf("�� ������ �� ��:\n");
	printScore(totalScore(p1, p2));
	
	printf("-----------------------------\n");
	p3 = createScore(100, 100);
	printScore(p3);

	free(p1);
	free(p2);
}