#include <stdio.h>
#include <stdlib.h>
//1) typedef으로 Score를 정의
typedef struct score {
	int midterm;
	int final;
}Score;
void printScore(Score* p) {
	printf("중간고사 성적은 %d\n", p->midterm);
	printf("학기말고사 성적은 %d\n", p->final);
}
Score* biggerScore(Score* p1, Score* p2) {
	int i = p1->midterm + p1->final;
	int j = p2->midterm + p2->final;

	if (i > j)
		return p1;
	return p2;
} 
Score* totalScore(Score* p1, Score* p2) {
	//구조체 변수로 선언 시 지역변수로 선언되므로 동적할당으로 선언하는 것이 필요
	Score* total = (Score*)malloc(sizeof(Score));//free는 어디서?

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
	//1) p1, p2를 각각 메모리 할당을 한 후
	p1 = (Score*)malloc(sizeof(Score));
	p2 = (Score*)malloc(sizeof(Score));
	// 가리키는 변수에 값 대입
	p1->midterm = 50;
	p1->final = 100;
	p2->midterm = 70;
	p2->final = 70;

	printScore(p1);
	printScore(p2);
	
	printf("-----------------------------\n");
	printf("둘중 성적이 좋은 점수:\n");
	printScore(biggerScore(p1, p2));
	
	printf("-----------------------------\n");
	printf("두 성적의 총 합:\n");
	printScore(totalScore(p1, p2));
	
	printf("-----------------------------\n");
	p3 = createScore(100, 100);
	printScore(p3);

	free(p1);
	free(p2);
}