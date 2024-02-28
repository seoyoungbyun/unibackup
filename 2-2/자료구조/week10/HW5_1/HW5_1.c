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
// 초기화 함수
void init(HeapType* h)
{
	h->heap_size = 0;
}
// 삽입 함수: 현재 요소의 개수가 heap_size 인 히프 h 에 item 을 삽입한다.
void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);
	// 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; // 새로운 노드를 삽입
}
// 삭제 함수
element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// 현재 노드의 자식노드중 더 작은 자식노드를 찾는다.
		if ((child < h->heap_size) &&
			(h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		// 한단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
void preorder(HeapType* h, int root) // 숙제
{
	if (h->heap_size < root)
		return;
	else {
		printf("%d ", h->heap[root]);
		preorder(h, root * 2);
		preorder(h, root * 2 + 1);
	}
}
int find(HeapType* h, int root, int key) // 숙제
{
	if (root > h->heap_size)
		return 0;
	if (key == h->heap[root].key)
		return root;
	else if (key > h->heap[root].key)//찾으려는 값이 현재 그래프 노드보다 크면 return하기(불필요한 탐색 방지)
		return 0;
	else
		return max(find(h, root * 2, key), find(h, root * 2 + 1, key));
}
int find2(HeapType* h, int key)//반복 + heap성질 이용하기(부모가 자식보다 크거나 같음
{
	int d = 2;
	int flag = 1;//key보다 작을때
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
			래밸의 모든 수가 key값보다 작으면 탐색 필요없음(하나라도 key보다 크거나 같은 값이 존재하면 밑 레벨 탐색)
		}
	}
	return 0;	*/
}
void print_sorted_value(HeapType heap) // delete_max_heap 을 이용한다//제공코드 체크
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
	* int s, i;  s<-각 레벨의 첫번째 노드

	for (s = 1; s <= h->heap_size; s *= 2) {	// s = 1, 2, 4, 8, ...
		for (i = s; i < s * 2 && i <= h->heap_size; i++) 	// e.g., when s = 4, i = 4, 5, 6, 7  i < s * 2 && i <= h->heap_size<-레벨 출력
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
	
	//oldkey idx보다 작은 인덱스의 key값 비교
	while (child <= h->heap_size) {
		// 현재 노드의 자식노드중 더 작은 자식노드를 찾는다.
		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		// 한단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	
	//oldkey idx보다 큰 인덱스의 key값 비교
	while ((parent != 1) && (temp.key > h->heap[parent / 2].key)) {
		h->heap[parent] = h->heap[parent / 2];
		parent /= 2;
	}
	h->heap[parent] = temp;
	/*
	int i, child;
	
	if (oldkey == newkey) return;
	i = find(h, 1, oldkey);//oldkey 찾기
	if (i == 0) return;		// fail to find oldkey
	if (newkey > oldkey) {	원래 수보다 바꿔야하는 수가 크다		// level up 
		위로 올라가기(삽입과 유사)

	}
	else {							// newkey < oldkey; level down
		밑으로 내려가기(삭제와 유사)


	}*/
}
int main(void)
{
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 }, eA = { 9 }, eB = { 19 }, eC = { 39 };
	element e4, e5, e6;
	int index;
	int key, oldKey, newKey;
	HeapType heap; // 히프 생성
	
	init(&heap); // 초기화
	
	printf("Step1: 삽입된 10, 5, 30 에 추가적으로 9, 19, 39 를 <삽입> 한다");
	insert_max_heap(&heap, e1);
	insert_max_heap(&heap, e2);
	insert_max_heap(&heap, e3);
	insert_max_heap(&heap, eA);
	insert_max_heap(&heap, eB);
	insert_max_heap(&heap, eC);
	
	printf("\nStep2: preorder, print_heap 함수 테스트\n");
	preorder(&heap, 1);
	printf("\n\n");
	print_heap(&heap);
	
	e4 = delete_max_heap(&heap);
	printf("\n 삭제: 루트가 삭제됨\n", e4.key);
	print_heap(&heap);
	
	printf("\nStep3: find 함수 테스트\n");
	printf("찾을 key 입력(-1 for exit):");
	scanf("%d", &key);
	while (key != -1) {
		if ((index = find(&heap, 1, key)) == 0)
			printf("%d는 없음\n", key);
		else
			printf("%d은 [%d]에 있음\n", key, index);
		printf("찾을 key 입력(-1 for exit):");
		scanf("%d", &key);
	}
	
	printf("\nStep4: print_sorted_value 함수 테스트\n");
	print_sorted_value(heap);
	
	printf("\nStep5: modify_priority 함수 테스트\n");
	printf("바꿀 key 입력(-1 for exit):");
	scanf("%d", &oldKey);
	while (oldKey != -1) {
		printf("새 key 입력:");
		scanf("%d", &newKey);
		modify_priority(&heap, oldKey, newKey);
		print_heap(&heap);
		
		printf("바꿀 key 입력(-1 for exit):");
		scanf("%d", &oldKey);
	}
}