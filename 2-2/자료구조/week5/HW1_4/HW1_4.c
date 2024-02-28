#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { // ��� Ÿ��
	element data;
	struct ListNode* link;
} ListNode;

void print_list(ListNode* head) // Ʋ��: �����غ��ô�
{
	ListNode* p;
	
	if (head == NULL) return;
	p = head->link;
	
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head->link);
	//printf("%d->", p->data); // ������ ��� ���
	printf("����Ʈ�� ��\n");
}
ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link; // (1)
		head->link = node; // (2)
	}
	return head; // ����� ��� �����͸� ��ȯ�Ѵ�. 
}
ListNode* insert_last(ListNode * head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link; // (1)
		head->link = node; // (2)
		head = node; // (3)
	}
	return head; // ����� ��� �����͸� ��ȯ�Ѵ�. 
}
ListNode* delete_first(ListNode * head)
{
	ListNode* temp;
	if (head == NULL) {
		printf("����Ʈ�� ��� ������ ����\n");
		return NULL;
	}
	else if (head == head->link) { //�� �ϳ��� ��尡 ��������
		temp = head;
		head = NULL;
		free(temp);
	}
	else {
		temp = head->link;
		head->link = temp->link;
		free(temp);
	}
	return head;
}
ListNode* delete_last(ListNode * head)
{
	ListNode* temp;
	ListNode* removed;
	if (head == NULL) {
		printf("����Ʈ�� ��� ������ ����\n");
		return NULL;
	}
	else if (head == head->link) { //�� �ϳ��� ��尡 ��������
		temp = head;
		head = NULL;
		free(temp);
	}
	else {
		temp = head->link;
		while (temp->link != head)
			temp = temp->link;
		
		temp->link = head->link;
		removed = head;
		head = temp;
		free(removed);
	}
	return head;
}
ListNode* search(ListNode * head, element data)
{
	if (head == NULL) {
		printf("����Ʈ�� ��� �־� ã�� ����\n");
		return NULL;
	}
	
	ListNode* temp = head->link;
	do {
		if (temp->data == data)
			return temp;
		temp = temp->link;
	} while (temp != head->link);

	printf("���� ã�� �� ����\n");
	return NULL;
}
int get_size(ListNode * head)
{
	ListNode* temp = head;
	if (head == NULL)
		return 0;

	int count = 0;
	do{
		temp = temp->link;
		count++;
	}while(temp->link != head->link);

	return count;
}
// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
int main(void)
{
	ListNode* head = NULL;
	
	// list = 10->20->30->40
	head = insert_last(head, 20);
	print_list(head);

	head = insert_last(head, 30);
	print_list(head);
	head = insert_last(head, 40);
	print_list(head);
	head = insert_first(head, 10);
	print_list(head);
	
	head = delete_first(head);
	print_list(head);
	
	head = delete_last(head);
	print_list(head);
	
	ListNode* s = search(head, 30);
	if (s != NULL)
		printf("data�� ���� ù��° ����� ���� %d\n", s->data);

	printf("����Ʈ�� ���̴� %d\n", get_size(head));
	return 0;
}