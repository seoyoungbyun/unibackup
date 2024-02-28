#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode { // ���߿��� ��� Ÿ��
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

// ���� ���� ����Ʈ�� �ʱ�ȭ
void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

// ���� ���� ����Ʈ�� ��带 ���
void print_dlist(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}

// ���ο� �����͸� ��� before�� �����ʿ� �����Ѵ�. 
void dinsert(DListNode *before, element data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;

	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}
// ��� removed�� �����Ѵ�. 
void ddelete(DListNode* head, DListNode* removed)
{
	if (removed == head) return;

	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}
void print_reverse_dlist(DListNode* head)
{
	DListNode* p;
	for (p = head->llink; p != head; p = p->llink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}
DListNode* search(DListNode* head, element data)
{
	DListNode* p;

	p = head->rlink;
	while (p != head) {
		if (p->data == data)
			return p;
		p = p->rlink;
	}
	printf("���� ã�� �� ����\n");
	return head;
}

// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
int main(void)
{
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	printf("�߰� �ܰ�\n");

	// �� �տ� ��带 ����
	dinsert(head, 10);
	print_dlist(head);
	dinsert(head, 20);
	print_dlist(head);
	dinsert(head, 30);
	print_dlist(head);
	
	// �� �ڿ� ��带 �����Ϸ���?
	dinsert(head->llink, 40);
	print_dlist(head);
	printf("\n���� �ܰ�\n");
	
	// �� ���� ��带 ����
	ddelete(head, head->rlink);
	print_dlist(head);
	
	// �� ���� ��带 �����Ϸ���?
	ddelete(head, head->llink);
	print_dlist(head);
	
	printf("\n�ݴ�� ���\n");
	print_reverse_dlist(head);

	printf("\n�� ã��\n");
	DListNode* s = search(head, 10);
	if (s != head)
		printf("data�� ���� ����� ���� %d\n", s->data);

	free(head);
	return 0;
}