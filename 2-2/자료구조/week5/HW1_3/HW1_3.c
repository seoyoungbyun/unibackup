#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

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
void display(ListNode* head) {
	ListNode* p;
	p = head;
	printf("< ");
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf(">\n");
}
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
int is_in_list(ListNode* head, element item) {
	if (head == NULL)error("탐색할 항목이 없음");

	ListNode* temp = head;
	while (temp != NULL) {
		if (temp->data == item)
			return 1;
		temp = temp->link;
	}

	return 0;
}
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
int get_total(ListNode* head) {
	if (head == NULL)error("더할 항목이 없음");

	int sum = 0;
	ListNode* temp = head;
	while (temp != NULL) {
		sum += temp->data;
		temp = temp->link;
	}

	return sum;
}
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

	return NULL;
}
ListNode* delete_by_key(ListNode* head, int key) {
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
}
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
void add_item(ListNode** phead, int new_item)
{
	int total;
	if (*phead == NULL)
		total = new_item;
	else 
		total = get_total(*phead) + new_item;

	if (total > 100) {
		printf("최대 무게<100kg> 초과로 아이템 %d를 추가할 수없음\n", new_item);
		return;
	}
	*phead = insert_first(*phead, new_item);
}
void delete_item(ListNode** phead, int item) {
	if (!is_in_list(*phead, item))
	{
		printf("아이템 %d는 보유하고 있지 않습니다.\n", item);
		return;
	}
	*phead = delete_by_key(*phead, item);
}
int main(void)
{
	ListNode* list = NULL;
	char ch;
	int w;

	printf("enter a<dd>, d<elete> or q<uit>:");
	scanf("%c", &ch);
	while (ch != 'q')
	{
		printf("enter the weight of the item:");
		scanf("%d", &w);
		switch (ch) {
			case 'a':
				add_item(&list, w);
				break;
			case 'd':
				delete_item(&list, w);
				break;
		}
		display(list);
		getchar();
		printf("enter a<dd>, d<elete> or q<uit>:");
		scanf("%c", &ch);
	}
}