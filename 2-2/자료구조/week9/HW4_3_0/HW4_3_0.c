#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX_STRING 100

typedef struct {
	int id;
	char name[MAX_STRING];
	char tel[MAX_STRING];
	char dept[MAX_STRING];
}element;
typedef struct TreeNode {
	element data;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* new_node(element item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}
void print(element data) {
	printf("-------------------------------\n");
	printf("학번: %d\n", data.id);
	printf("이름: %s\n", data.name);
	printf("전화번호: %s\n", data.tel);
	printf("학과: %s\n", data.dept);
}
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);// 왼쪽서브트리 순회
		print(root->data); // 노드 방문
		inorder(root->right);// 오른쪽서브트리 순회
	}
}
//탐색(순환)
TreeNode* search(TreeNode* node, int id)
{
	if (node == NULL) return NULL;
	if (id == node->data.id) return node;
	else if (id < node->data.id)
		return search(node->left, id);
	else
		return search(node->right, id);
}
TreeNode* insert_node(TreeNode* root, element key)
{
	// 트리가 공백이면 새로운 노드를 반환한다.
	if (root == NULL) return new_node(key);
	// 그렇지 않으면 순환적으로 트리를 내려간다.
	if (key.id < root->data.id)
		root->left = insert_node(root->left, key);
	else if (key.id > root->data.id)
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
// 삭제 함수
TreeNode* delete_node(TreeNode* root, int key)
{
	TreeNode* temp;
	if (root == NULL) return root;
	// 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임
	if (key < root->data.id)
		root->left = delete_node(root->left, key);
	// 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
	else if (key > root->data.id)
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
		root->data = temp->data;
		// 중외 순회시 후계 노드를 삭제한다.
		root->right = delete_node(root->right, temp->data.id);
	}
	return root;
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
	element key;

	printf("Enter i<nsert>,d<elete>,s<earch>,p<rint>,c<ount>,q<uit>:");
	scanf("%c", &c);

	while (c != 'q') {
		switch (c) {
			case 'i':
				printf("학번 입력:");
				scanf("%d", &key.id);
				printf("이름 입력:");
				scanf("%s", key.name);
				printf("전화번호 입력:");
				scanf("%s", key.tel);
				printf("학과 입력:");
				scanf("%s", key.dept);
				root = insert_node(root, key);
				break;
			case 'd':
				printf("삭제할 학번 입력:");
				scanf("%d", &key.id);
				root = delete_node(root, key.id);
				break;
			case 's':
				printf("탐색할 학번 입력:");
				scanf("%d", &key.id);
				TreeNode* node = search(root, key.id);
				if (node != NULL)
					print(node->data);
				else
					printf("id가 %d인 학생은 없읍니다.\n", key.id);
				break;
			case 'p':
				printf("학생 정보 학번 순 출력\n");
				inorder(root);
				printf("\n");
				break;
			case 'c':
				printf("현재 저장된 학생의 총 수는 %d\n", count(root));
				break;
			default:
				break;
		}
		getchar();
		printf("Enter i<nsert>,d<elete>,s<earch>,p<rint>,c<ount>,q<uit>:");
		scanf("%c", &c);
	}
}