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
ListNode* insert_next(ListNode* head, ListNode *pre, element value)
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
void print_list(ListNode* head) {
	ListNode* p;
	p = head;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("NULL \n");
	//printf("\n");
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
int main(void)
{
	ListNode* list1 = NULL, * list2 = NULL, * list3;

	//list1 = 30->20->10->를 만든다. 이때 10, 20, 30의 순으로 노드를 삽입한다. 
	list1 = insert_first(list1, 10);
	list1 = insert_first(list1, 20);
	list1 = insert_first(list1, 30);
	//list1을 출력
	printf("list1 = ");
	print_list(list1);

	//list1의 맨 앞 노드를 삭제한다 즉, list1 = 20->30-> 
	list1 = delete_first(list1);
	printf("list1 = ");
	//list1을 출력
	print_list(list1);

	//list2 = 11->22->33->44->를 만든다. 이때 11, 22, 33, 44의 순으로 노드를 삽입한다. 
	for (int i = 1; i <= 4; i++)
		list2 = insert_last(list2, i * 11);
	//list2를 출력
	printf("list2 = ");
	print_list(list2);
	//list2의 맨 뒤 노드를 삭제한다. 즉, list2 = 11->22->33->
	delete_last(list2);
	//list2를 출력
	printf("list2 = ");
	print_list(list2);
	//list2를 역순으로 바꾼 리스트를 list3가 가리키게 한다. list3 = 33->22->11->를 만든다.
	list3 = reverse(list2);
	//list3를 출력한다.
	printf("list3 = ");
	print_list(list3);
	// list1 = 20->30->33->22->11->를 만든다. 즉, list1과 list3를 합쳐서 list1이 가리키게 한다.
	list1 = concat(list1, list3);
	//list1을 출력한다.
	printf("list1 = ");
	print_list(list1);
	//(A) 주의: 여기서부터는 list1만 사용하여 함수들을 테스트하자 
	(is_in_list(list1, 22)) ? printf("22는 list1에 있다.\n") : printf("22는 list1에 없다.\n");
	(is_in_list(list1, 15)) ? printf("15는 list1에 있다.\n") : printf("15는 list1에 없다.\n");

	printf("list1에는 노드가 %d개 있다.\n", get_length(list1));
	printf("list1의 모든 데이터 값의 합은 %d이다.\n", get_total(list1));
	
	printf("list1의 3번째 위치에 있는 노드의 data는 %d\n", get_entry(list1, 3));

	list1 = delete_by_key(list1, 10);
	printf("list1 = ");
	print_list(list1);

	list1 = insert_pos(list1, 2, 44);
	printf("list1 = ");
	print_list(list1);

	list1 = delete_pos(list1, 3);
	printf("list1 = ");
	print_list(list1);
}