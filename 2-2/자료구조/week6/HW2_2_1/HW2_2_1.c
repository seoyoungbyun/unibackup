#include <stdio.h>
#include <malloc.h>

// ������ ���� Ÿ�� ����
typedef int element;
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
		int item = temp->item;
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
		printf("%d <- top\n", peek(s));
		StackNode* temp = s->top->link;
		while (temp != NULL) {
			printf("%d\n", temp->item);
			temp = temp->link;
		}
	}
	printf("--\n");
}
// �� �Լ�
void main()
{
	LinkedStackType s;
	init(&s);
	stack_print(&s);

	push(&s, 10);
	stack_print(&s);
	
	push(&s, 20);
	stack_print(&s);
	
	push(&s, 30);
	stack_print(&s);
	
	push(&s, 40);
	stack_print(&s);
	
	pop(&s);
	stack_print(&s);
	
	push(&s, 50);
	stack_print(&s);
	
	pop(&s);
	stack_print(&s);
	
	pop(&s);
	stack_print(&s);
	
	pop(&s);
	stack_print(&s);
}