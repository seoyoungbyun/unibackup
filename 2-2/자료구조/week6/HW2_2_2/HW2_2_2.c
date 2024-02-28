#include <stdio.h>
#include <malloc.h>

#define MAX_STRING_SIZE 100
// ������ ���� Ÿ�� ����
typedef struct {
	int data;
	char str[MAX_STRING_SIZE];
} element;
typedef struct StackNode {
	element item;
	struct StackNode* link;
} StackNode;

typedef struct {
	StackNode* top;
} LinkedStackType;
// �ʱ�ȭ �Լ�
void init(LinkedStackType* s)
{
	s->top = NULL;
}
// ���� ���� ���� �Լ�
int is_empty(LinkedStackType* s)
{
	return (s->top == NULL);
}
// ��ȭ ���� ���� �Լ�
int is_full(LinkedStackType* s) // Stack �������� �ϳ��� ���ܵξ����� �׻� ������ ��ȯ. �� �� ������ ���� ����
{
	return 0;
}
// ���� �Լ�
void push(LinkedStackType* s, element item)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "�޸� �Ҵ翡��\n");
		return;
	}
	else {
		temp->item = item;
		temp->link = s->top;
		s->top = temp;
	}
}
// ���� �Լ�
element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		element item = temp->item;
		s->top = s->top->link;
		free(temp);
		return item;
	}
}
// ��ũ �Լ�
element peek(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else {
		return s->top->item;
	}
}
void stack_print(LinkedStackType* s) {
	if (is_empty(s)) {
		printf("<empty>\n--\n");
		return;
		//fprintf(stderr, "<empty>\n--\n");
	}
	else {
		printf("[%d, %s] <- top\n", peek(s).data, peek(s).str);
		StackNode* temp = s->top->link;
		while (temp != NULL) {
			printf("[%d, %s]\n", temp->item.data, temp->item.str);
			temp = temp->link;
		}
	}
	printf("--\n");
}
void element_push(element* ie, int num, char string[MAX_STRING_SIZE]) {
	ie->data = num;
	strcpy(ie->str, string);
}
// �� �Լ�
void main()
{
	LinkedStackType s;
	init(&s);
	stack_print(&s);

	element ie;
	element_push(&ie, 10, "ten");
	push(&s, ie);
	stack_print(&s);

	element_push(&ie, 20, "twenty");
	push(&s, ie);
	stack_print(&s);

	element_push(&ie, 30, "thirty");
	push(&s, ie);
	stack_print(&s);

	element_push(&ie, 40, "forty");
	push(&s, ie);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	element_push(&ie, 50, "fifty");
	push(&s, ie);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	pop(&s);
	stack_print(&s);
}