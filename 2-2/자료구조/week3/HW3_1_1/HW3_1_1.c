#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 3 //3으로 설정
#define MAX_STRING 100 // 추가

typedef struct { //수정
	char name[MAX_STRING];
} element;

typedef struct {
	element  queue[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;
//
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 초기화 함수
void init(QueueType* q)
{
	q->front = q->rear = 0;
}
// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}
// 포화 상태 검출 함수
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
// 삽입 함수
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}
// 삭제 함수
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}
// 보기 함수
element peek(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}

int get_count(QueueType* q)
{
	// 코드 추가
	if (is_empty(q))
		return 0;
	int num = q->rear - q->front;

	if (num < 0)
		num *= -1;

	return num;
}
/*교수님이 제공해주신 코드
int get_count(QueueType *q)
{
if (q->front <= q->rear) 
				return (q->rear - q->front)
     else
				return (q->rear + MAX_QUEUE_SIZE - q->front)
}
*/
void print_queue(QueueType* q) // 추가, 20141016 수정
{
	// 코드 추가
	//printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%s ", q->queue[i].name);
			if (i == q->rear)
				break;
		} while (i != q->front);//i != q->rear + 1 % MAX_QUEUE_SIZE
	}
	printf("\n");
}
/*교수님이 제공해주신 코드
void print_queue(QueueType *q) 
{
     int temp  = (q->front + 1) % MAX_QUEUE_SIZE; 
     while (temp != (q->rear + 1) % MAX_QUEUE_SIZE) { 
          printf("%s ", q->queue[temp].name);
          temp = (temp + 1) % MAX_QUEUE_SIZE;
     }
     printf("\n");
}
*/
void try_match(char* name, QueueType* partnerQ, QueueType* myQ) //추가 부분: 더 좋은 함수 이름??
{
	// 코드 추가
	element newP;
	strcpy(newP.name, name);
	if (is_empty(partnerQ)) {
		printf("아직 대상자가 없습니다.");
		if (!is_full(myQ)) {
			printf("기다려주십시요.\n");
			enqueue(myQ, newP);
		}
		else
			printf("대기자가 꽉찼으니 담기회를 이용\n");
	}
	else {
		enqueue(myQ, newP);
		printf("커플이 탄생했습니다! %s과 %s\n", dequeue(myQ), dequeue(partnerQ));//커플인지 확인하고 그 다음 꽉찼는지 확인/리스트에 넣기
	}
}
/*
// 2)를 테스트하기 위한 임시 main 함수
int main(void)
{
	QueueType manQ;
	element newPerson;
	char name[MAX_STRING];

	init(&manQ);

	printf("이름을 입력:");
	scanf("%s", newPerson.name);
	enqueue(&manQ, newPerson);
	printf("%d명: ", get_count(&manQ));
	print_queue(&manQ);

	printf("이름을 입력:");
	scanf("%s", newPerson.name);
	enqueue(&manQ, newPerson);
	printf("%d명: ", get_count(&manQ));
	print_queue(&manQ);

	printf("이름을 입력:");
	scanf("%s", newPerson.name);
	enqueue(&manQ, newPerson); // 원형큐의 사이즈가 3이므로 3번째 요소를 넣으려하면 포화 에러가 난다
	printf("%d명: ", get_count(&manQ));
	print_queue(&manQ);
}
*/

int main(void)
{
	 QueueType manQ, womanQ;
	 char choice;
	 char name[MAX_STRING];
	 char gender;

	 init(&manQ);
	 init(&womanQ);

	 printf("미팅 주선 프로그램입니다.\n");

	 printf("i(nsert, 고객입력), c(heck, 대기자 체크), q(uit):");
	 scanf("%c", &choice);

	 while (choice != 'q') {
		  switch(choice) {
		  case 'i':
			   printf("이름을 입력:");
			   scanf("%s", name);
			   while (getchar() != '\n'); // 버퍼 비우기
			   printf("성별을 입력(m or f):");
			   scanf("%c", &gender);
			   if (gender == 'm')
					try_match(name, &womanQ, &manQ);
			   else
					try_match(name, &manQ, &womanQ);
			   break;
		  case 'c':
			   printf("남성 대기자 %d명: ", get_count(&manQ));
			   print_queue(&manQ);
			   printf("여성 대기자 %d명: ", get_count(&womanQ));
			   print_queue(&womanQ);
		  }
		  while (getchar() != '\n'); // 버퍼 비우기
		  printf("i(nsert, 고객입력), c(heck, 대기자 체크), q(uit):");
		  scanf("%c", &choice);
	 }
}
