#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
#define TRUE 1
#define FALSE 0
typedef struct {
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;
// �ʱ�ȭ �Լ�
void init(HeapType* h)
{
	h->heap_size = 0;
}
// ���� �Լ�: ���� ����� ������ heap_size �� ���� h �� item �� �����Ѵ�.
void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);
	// Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; // ���ο� ��带 ����
}
// ���� �Լ�
element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// ���� ����� �ڽĳ���� �� ���� �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) &&
			(h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		// �Ѵܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
void preorder(HeapType* h, int root) // ����
{
	if (h->heap_size < root)
		return;
	else {
		printf("%d ", h->heap[root]);
		preorder(h, root * 2);
		preorder(h, root * 2 + 1);
	}
}
int find(HeapType* h, int root, int key) // ����
{
	if (root > h->heap_size)
		return 0;
	if (key == h->heap[root].key)
		return root;
	else if (key > h->heap[root].key)//ã������ ���� ���� �׷��� ��庸�� ũ�� return�ϱ�(���ʿ��� Ž�� ����)
		return 0;
	else
		return max(find(h, root * 2, key), find(h, root * 2 + 1, key));
}
int find2(HeapType* h, int key)//�ݺ� + heap���� �̿��ϱ�(�θ� �ڽĺ��� ũ�ų� ����
{
	int d = 2;
	int flag = 1;//key���� ������
	for (int i = 1; i <= h->heap_size; i++)
	{
		if (h->heap[i].key == key)
			return i;
		
		if (h->heap[i].key > key)
			flag = 0;
		if (i == d - 1) {
			if (flag == 1)
				return 0;
			flag = 1;
			d *= 2;
		}
	}
	return 0;
	/*int s, i;

	for (s = 1; s <= h->heap_size; s *= 2) {	// s = 1, 2, 4, 8, ...
		for (i = s; i < s * 2 && i <= h->heap_size; i++) {	// e.g., when s = 4, i = 4, 5, 6, 
			������ ��� ���� key������ ������ Ž�� �ʿ����(�ϳ��� key���� ũ�ų� ���� ���� �����ϸ� �� ���� Ž��)
		}
	}
	return 0;	*/
}
void print_sorted_value(HeapType heap) // delete_max_heap �� �̿��Ѵ�//�����ڵ� üũ
{
	element a[MAX_ELEMENT];
	int size = heap.heap_size;
	for (int i = 1; i <= size; i++)
		a[i] = delete_max_heap(&heap);
	for (int i = 1; i <= size; i++)
		printf("%d ", a[i]);
	printf("\n");

}
void print_heap(HeapType* h)
{
	int i;
	int d = 2;
	for (i = 1; i <= h->heap_size; i++)
	{
		printf("%d ", h->heap[i]);
		if (i == d - 1) {
			d *= 2;
			printf("\n");
		}
	}
	if (i != d - 1)
		printf("\n");
	/*
	* int s, i;  s<-�� ������ ù��° ���

	for (s = 1; s <= h->heap_size; s *= 2) {	// s = 1, 2, 4, 8, ...
		for (i = s; i < s * 2 && i <= h->heap_size; i++) 	// e.g., when s = 4, i = 4, 5, 6, 7  i < s * 2 && i <= h->heap_size<-���� ���
			printf("%d ", h->heap[i]);
		printf("\n");
	}
	*/
}
void modify_priority(HeapType* h, int oldkey, int newkey)
{
	int idx;
	for (idx = 1; idx <= h->heap_size; idx++)
		if (h->heap[idx].key == oldkey)
			break;
	
	int parent, child;
	element temp = { newkey };
	parent = idx;
	child = idx * 2;
	
	//oldkey idx���� ���� �ε����� key�� ��
	while (child <= h->heap_size) {
		// ���� ����� �ڽĳ���� �� ���� �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		// �Ѵܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	
	//oldkey idx���� ū �ε����� key�� ��
	while ((parent != 1) && (temp.key > h->heap[parent / 2].key)) {
		h->heap[parent] = h->heap[parent / 2];
		parent /= 2;
	}
	h->heap[parent] = temp;
	/*
	int i, child;
	
	if (oldkey == newkey) return;
	i = find(h, 1, oldkey);//oldkey ã��
	if (i == 0) return;		// fail to find oldkey
	if (newkey > oldkey) {	���� ������ �ٲ���ϴ� ���� ũ��		// level up 
		���� �ö󰡱�(���԰� ����)

	}
	else {							// newkey < oldkey; level down
		������ ��������(������ ����)


	}*/
}
int main(void)
{
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 }, eA = { 9 }, eB = { 19 }, eC = { 39 };
	element e4, e5, e6;
	int index;
	int key, oldKey, newKey;
	HeapType heap; // ���� ����
	
	init(&heap); // �ʱ�ȭ
	
	printf("Step1: ���Ե� 10, 5, 30 �� �߰������� 9, 19, 39 �� <����> �Ѵ�");
	insert_max_heap(&heap, e1);
	insert_max_heap(&heap, e2);
	insert_max_heap(&heap, e3);
	insert_max_heap(&heap, eA);
	insert_max_heap(&heap, eB);
	insert_max_heap(&heap, eC);
	
	printf("\nStep2: preorder, print_heap �Լ� �׽�Ʈ\n");
	preorder(&heap, 1);
	printf("\n\n");
	print_heap(&heap);
	
	e4 = delete_max_heap(&heap);
	printf("\n ����: ��Ʈ�� ������\n", e4.key);
	print_heap(&heap);
	
	printf("\nStep3: find �Լ� �׽�Ʈ\n");
	printf("ã�� key �Է�(-1 for exit):");
	scanf("%d", &key);
	while (key != -1) {
		if ((index = find(&heap, 1, key)) == 0)
			printf("%d�� ����\n", key);
		else
			printf("%d�� [%d]�� ����\n", key, index);
		printf("ã�� key �Է�(-1 for exit):");
		scanf("%d", &key);
	}
	
	printf("\nStep4: print_sorted_value �Լ� �׽�Ʈ\n");
	print_sorted_value(heap);
	
	printf("\nStep5: modify_priority �Լ� �׽�Ʈ\n");
	printf("�ٲ� key �Է�(-1 for exit):");
	scanf("%d", &oldKey);
	while (oldKey != -1) {
		printf("�� key �Է�:");
		scanf("%d", &newKey);
		modify_priority(&heap, oldKey, newKey);
		print_heap(&heap);
		
		printf("�ٲ� key �Է�(-1 for exit):");
		scanf("%d", &oldKey);
	}
}