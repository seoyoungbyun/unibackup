#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_CHAR_PER_LINE 100

typedef struct {
	char line[MAX_CHAR_PER_LINE];
} element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;
void display_te(ListNode* head) {
	ListNode* p;
	p = head;
	int count = 1;

	printf("----------text edited---------\n");
	while (p != NULL) {
		printf("(%d) %s", count++, p->data);
		p = p->link;
	}
}
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_next(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;

	return head;
}
ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;

	return head;
}
ListNode* insert_last(ListNode* head, element value) {
	ListNode* temp = head;
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL;

	if (head == NULL)
		head = p;
	else {
		while (temp->link != NULL)
			temp = temp->link;
		temp->link = p;
	}
	return head;
}
ListNode* delete_next(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);

	return head;
}
ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL) error("삭제할 항목이 없음");

	removed = head;
	head = removed->link;
	free(removed);

	return head;
}
ListNode* delete_last(ListNode* head) {
	ListNode* temp = head;
	ListNode* prevTemp = NULL;
	ListNode* removed;
	if (head == NULL) error("삭제할 항목이 없음");

	if (head->link == NULL)
	{
		removed = head;
		free(removed);
		head = NULL;
	}
	else {
		while (temp->link != NULL) {
			prevTemp = temp;
			temp = temp->link;
		}
		prevTemp->link = NULL;
		removed = temp;
		free(removed);
	}

	return head;
}
/*void print_list(ListNode* head) {
	ListNode* p;
	p = head;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("NULL \n");
	//printf("\n");
}*/
/*ListNode* search(ListNode* head, element x) {
	ListNode* p;
	p = head;

	while (p != NULL) {
		if (p->data == x)
			return p;
		p = p->link;
	}

	return NULL;
}*/
ListNode* concat(ListNode* head1, ListNode* head2) {
	ListNode* p;
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;

		return head1;
	}
}
ListNode* reverse(ListNode* head) {
	ListNode* p, * q, * r;
	p = head;
	q = NULL;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}
/*int is_in_list(ListNode* head, element item) {
	if (head == NULL)error("탐색할 항목이 없음");

	ListNode* temp = head;
	while (temp != NULL) {
		if (temp->data == item)
			return 1;
		temp = temp->link;
	}

	return 0;
}*/
int get_length(ListNode* head) {
	if (head == NULL)error("반환할 항목이 없음");
	int num = 0;

	ListNode* temp = head;
	while (temp != NULL) {
		num++;
		temp = temp->link;
	}

	return num;
}
/*int get_total(ListNode* head) {
	if (head == NULL)error("더할 항목이 없음");

	int sum = 0;
	ListNode* temp = head;
	while (temp != NULL) {
		sum += temp->data;
		temp = temp->link;
	}

	return sum;
}*/
element get_entry(ListNode* head, int pos) {
	//pos 유효성 검증
	if (pos < 0 || pos > get_length(head) - 1)error("pos위치 오류");

	int count = 0;
	ListNode* temp = head;
	while (temp != NULL) {
		if (count == pos)
			return temp->data;
		temp = temp->link;
		count++;
	}
}
/*ListNode* delete_by_key(ListNode* head, int key) {
	if (head == NULL)error("삭제할 항목이 없음");

	ListNode* temp = head;
	ListNode* prevTemp = NULL;
	ListNode* removed;

	if (head->data == key)
	{
		removed = head;
		head = removed->link;//head = head->link
		free(removed);

		return head;
	}
	else {
		while (temp != NULL) {
			if (key == temp->data)
			{
				removed = prevTemp->link;
				prevTemp->link = removed->link;
				free(removed);

				return head;
			}
			prevTemp = temp;
			temp = temp->link;
		}
	}

	return head;
}*/
ListNode* insert_pos(ListNode* head, int pos, element value) {
	//pos 유효성 검증
	if (pos < 0 || pos > get_length(head))error("pos위치 오류");

	ListNode* temp = head;
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	if (pos == 0) {
		//head = insert_first(head, value);
		p->data = value;
		p->link = head;
		head = p;

		return head;
	}
	else {
		int count = 0;
		while (temp != NULL) {
			if (count == pos - 1) {
				//head = insert_next(head, temp, value);
				p->data = value;
				p->link = temp->link;
				temp->link = p;

				return head;
			}
			count++;
			temp = temp->link;
		}
	}

	return head;
}
ListNode* delete_pos(ListNode* head, int pos) {
	//pos 유효성 검증
	if (pos < 0 || pos > get_length(head) - 1)error("pos위치 오류");

	int count = 0;
	ListNode* temp = head;
	ListNode* removed;
	if (pos == 0) {
		//head = delete_first(head)
		removed = head;
		head = removed->link;
		free(removed);

		return head;
	}
	else {
		while (temp != NULL) {
			if (count == pos - 1) {
				//head = delete_next(head, temp);
				removed = temp->link;
				temp->link = removed->link;
				free(removed);

				return head;
			}
			count++;
			temp = temp->link;
		}
	}

	return head;
}
char askChoice(void) {
	char choice;
	printf("------------------------------\n"); 
	printf("a: 텍스트 끝에 라인 추가\n"); 
	printf("i: 라인 번호로 라인 추가\n"); 
	printf("d: 라인 번호로 라인 삭제\n"); 
	printf("v: 라인 번호로 해당 라인 출력\n"); 
	printf("p: 전체 텍스트 출력\n"); 
	printf("q: 끝\n");
	
	printf("메뉴 선택:"); 
	scanf("%c", &choice);
	return choice;
}
int main(void) // 3)
{
	ListNode* list = NULL;
	char choice;
	int lineNb;
	element newElement;

	while ((choice = askChoice()) != 'q') {
		switch (choice) {
			case 'a':
				printf("텍스트 끝에 삽입할 라인: ");
				while (getchar() != '\n');
				fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);
				
				list = insert_last(list, newElement);
				display_te(list);
				break;
			case 'i':
				printf("삽입할 라인 번호: ");
				scanf("%d", &lineNb);
				
				printf("삽입할 라인: ");
				while (getchar() != '\n');
				fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);

				list = insert_pos(list, lineNb - 1, newElement);
				display_te(list);
				break;
			case 'd':
				printf("삭제할 라인 번호: ");
				scanf("%d", &lineNb);
				while (getchar() != '\n');

				list = delete_pos(list, lineNb - 1);
				display_te(list);
				break;
			case 'v':
				printf("출력할 라인 번호: ");
				scanf("%d", &lineNb);
				while (getchar() != '\n');
				
				printf("(%d) %s", lineNb, get_entry(list, lineNb - 1));
				break;
			case 'p':
				display_te(list);
				while (getchar() != '\n');
		}
		//while (getchar() != '\n'); // 버퍼를 비운다
	}
}