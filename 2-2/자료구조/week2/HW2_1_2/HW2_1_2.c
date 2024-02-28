#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 3
#define MAX_STRING_SIZE 100

typedef struct {
	int data;
	char str[MAX_STRING_SIZE];
} element;

typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;


void init_stack(StackType* s)
{
	s->top = -1;
}

int is_empty(StackType* s)
{
	return (s->top == -1);
}
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}

element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "<empty>\n--\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}

element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "<empty>\n--\n");
		exit(1);
	}
	else return s->stack[s->top];
}

void stack_print(StackType* s) {
	if (is_empty(s)) {
		printf("<empty>\n--\n");
		return;
		//fprintf(stderr, "<empty>\n--\n");
	}
	else {
		printf("[%d, %s] <- top\n", peek(s).data, peek(s).str);
		for (int i = (s->top) - 1; i >= 0; i--)
			printf("[%d, %s]\n", s->stack[i].data, s->stack[i].str);
	}
	printf("--\n");
}
void element_push(element* ie, int num, char string[MAX_STRING_SIZE]) {
	ie->data = num;
	strcpy(ie->str, string);
}
int main(void)
{
	StackType s;
	
	init_stack(&s);
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