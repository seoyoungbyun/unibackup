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
	printf("�й�: %d\n", data.id);
	printf("�̸�: %s\n", data.name);
	printf("��ȭ��ȣ: %s\n", data.tel);
	printf("�а�: %s\n", data.dept);
}
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);// ���ʼ���Ʈ�� ��ȸ
		print(root->data); // ��� �湮
		inorder(root->right);// �����ʼ���Ʈ�� ��ȸ
	}
}
//Ž��(��ȯ)
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
	// Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�.
	if (root == NULL) return new_node(key);
	// �׷��� ������ ��ȯ������ Ʈ���� ��������.
	if (key.id < root->data.id)
		root->left = insert_node(root->left, key);
	else if (key.id > root->data.id)
		root->right = insert_node(root->right, key);
	// ����� ��Ʈ �����͸� ��ȯ�Ѵ�.
	return root;
}
TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;
	while (current->left != NULL) // �� ���� �ܸ� ��带 ã���� ������
		current = current->left;
	return current;
}
// ���� �Լ�
TreeNode* delete_node(TreeNode* root, int key)
{
	TreeNode* temp;
	if (root == NULL) return root;
	// ���� Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� �ִ� ����
	if (key < root->data.id)
		root->left = delete_node(root->left, key);
	// ���� Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� �ִ� ����
	else if (key > root->data.id)
		root->right = delete_node(root->right, key);
	// Ű�� ��Ʈ�� ������ �� ��带 �����ϸ� ��
	else {
		// ù ��°�� �� ��° ���
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
		// �� ��° ���
		temp = min_value_node(root->right);
		// �߿� ��ȸ�� �İ� ��带 �����Ѵ�.
		root->data = temp->data;
		// �߿� ��ȸ�� �İ� ��带 �����Ѵ�.
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
				printf("�й� �Է�:");
				scanf("%d", &key.id);
				printf("�̸� �Է�:");
				scanf("%s", key.name);
				printf("��ȭ��ȣ �Է�:");
				scanf("%s", key.tel);
				printf("�а� �Է�:");
				scanf("%s", key.dept);
				root = insert_node(root, key);
				break;
			case 'd':
				printf("������ �й� �Է�:");
				scanf("%d", &key.id);
				root = delete_node(root, key.id);
				break;
			case 's':
				printf("Ž���� �й� �Է�:");
				scanf("%d", &key.id);
				TreeNode* node = search(root, key.id);
				if (node != NULL)
					print(node->data);
				else
					printf("id�� %d�� �л��� �����ϴ�.\n", key.id);
				break;
			case 'p':
				printf("�л� ���� �й� �� ���\n");
				inorder(root);
				printf("\n");
				break;
			case 'c':
				printf("���� ����� �л��� �� ���� %d\n", count(root));
				break;
			default:
				break;
		}
		getchar();
		printf("Enter i<nsert>,d<elete>,s<earch>,p<rint>,c<ount>,q<uit>:");
		scanf("%c", &c);
	}
}