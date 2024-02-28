#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* new_node(int item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
void preorder(TreeNode* root) {
	if (root) {
		printf("%d ", root->key); // 노드 방문
		preorder(root->left);// 왼쪽서브트리 순회
		preorder(root->right);// 오른쪽서브트리 순회
	}
}
//탐색(순환)
TreeNode* search(TreeNode* node, int key)
{
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}
TreeNode* insert_node(TreeNode* root, int key)
{
	// 트리가 공백이면 새로운 노드를 반환한다.
	if (root == NULL) return new_node(key);
	// 그렇지 않으면 순환적으로 트리를 내려간다.
	if (key < root->key)
		root->left = insert_node(root->left, key);
	else if (key > root->key)
		root->right = insert_node(root->right, key);
	// 변경된 루트 포인터를 반환한다.
	return root;
}
TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;
	while (current->left != NULL) // 맨 왼쪽 단말 노드를 찾으러 내려감
		current = current->left;
	return current;
}
int get_minimum(TreeNode* node)
{
	if (node == NULL)
		return NULL;

	TreeNode* current = node;
	while (current->left != NULL) // 맨 왼쪽 단말 노드를 찾으러 내려감
		current = current->left;
	return current->key;
}
int get_maximum(TreeNode* node)
{
	if (node == NULL)
		return NULL;
	
	TreeNode* current = node;
	while (current->right != NULL) // 맨 왼쪽 단말 노드를 찾으러 내려감
		current = current->right;
	return current->key;
}
// 삭제 함수
TreeNode* delete_node(TreeNode* root, int key)
{
	TreeNode* temp;
	if (root == NULL) return root;
	// 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임
	if (key < root->key)
		root->left = delete_node(root->left, key);
	// 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
	else if (key > root->key)
		root->right = delete_node(root->right, key);
	// 키가 루트와 같으면 이 노드를 삭제하면 됨
	else {
		// 첫 번째나 두 번째 경우
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		// 세 번째 경우
		temp = min_value_node(root->right);
		// 중외 순회시 후계 노드를 복사한다.
		root->key = temp->key;
		// 중외 순회시 후계 노드를 삭제한다.
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}
int get_height(TreeNode* root)
{
	int h = 0;
	if (root != NULL) {
		int l = get_height(root->left);
		int r = get_height(root->right);
		if (l > r)
			h = 1 + l;
		else
			h = 1 + r;
	}
	return h;
}
int count(TreeNode* root)
{
	int c = 0;
	if (root != NULL)
		c = 1 + count(root->left) + count(root->right);
	return c;
}
int main(void)
{
	TreeNode* root = NULL;
	char c;
	int key;

	printf("Enter i<nsert>,d<elete>,s<earch>,p<rint>,h<eight>,c<ount>,m<ax>,n<min>,q<uit>:");
	scanf("%c", &c);

	while (c != 'q') {
		switch (c) {
			case 'i':
				printf("삽입할 key값 입력:");
				scanf("%d", &key);
				root = insert_node(root, key);
				break;
			case 'd':
				printf("삭제할 key값 입력:");
				scanf("%d", &key);
				root = delete_node(root, key);
				break;
			case 's':
				printf("탐색할 key값 입력:");
				scanf("%d", &key);
				if (search(root, key) != NULL)
					printf("있음\n");
				else
					printf("없음\n");
				break;
			case 'p':
				preorder(root);
				printf("\n");
				break;
			case 'h':
				printf("트리의 높이는 %d\n", get_height(root));
				break;
			case 'c':
				printf("노드의 개수는 %d\n", count(root));
				break;
			case 'm':
				key = get_maximum(root);
				if (key != NULL)
					printf("가장 큰 값은 %d\n", get_maximum(root));
				else
					printf("아직 노드가 존재하지 않음\n");
				break;
			case 'n':
				key = get_minimum(root);
				if (key != NULL)
					printf("가장 작은 값은 %d\n", get_minimum(root));
				else
					printf("아직 노드가 존재하지 않음\n");
		}
		getchar();
		printf("Enter i<nsert>,d<elete>,s<earch>,p<rint>,h<eight>,c<ount>,m<ax>,n<min>,q<uit>:");
		scanf("%c", &c);
	}
}