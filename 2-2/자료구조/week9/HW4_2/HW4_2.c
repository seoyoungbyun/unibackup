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
		printf("%d ", root->key); // ��� �湮
		preorder(root->left);// ���ʼ���Ʈ�� ��ȸ
		preorder(root->right);// �����ʼ���Ʈ�� ��ȸ
	}
}
//Ž��(��ȯ)
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
	// Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�.
	if (root == NULL) return new_node(key);
	// �׷��� ������ ��ȯ������ Ʈ���� ��������.
	if (key < root->key)
		root->left = insert_node(root->left, key);
	else if (key > root->key)
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
int get_minimum(TreeNode* node)
{
	if (node == NULL)
		return NULL;

	TreeNode* current = node;
	while (current->left != NULL) // �� ���� �ܸ� ��带 ã���� ������
		current = current->left;
	return current->key;
}
int get_maximum(TreeNode* node)
{
	if (node == NULL)
		return NULL;
	
	TreeNode* current = node;
	while (current->right != NULL) // �� ���� �ܸ� ��带 ã���� ������
		current = current->right;
	return current->key;
}
// ���� �Լ�
TreeNode* delete_node(TreeNode* root, int key)
{
	TreeNode* temp;
	if (root == NULL) return root;
	// ���� Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� �ִ� ����
	if (key < root->key)
		root->left = delete_node(root->left, key);
	// ���� Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� �ִ� ����
	else if (key > root->key)
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
		root->key = temp->key;
		// �߿� ��ȸ�� �İ� ��带 �����Ѵ�.
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
				printf("������ key�� �Է�:");
				scanf("%d", &key);
				root = insert_node(root, key);
				break;
			case 'd':
				printf("������ key�� �Է�:");
				scanf("%d", &key);
				root = delete_node(root, key);
				break;
			case 's':
				printf("Ž���� key�� �Է�:");
				scanf("%d", &key);
				if (search(root, key) != NULL)
					printf("����\n");
				else
					printf("����\n");
				break;
			case 'p':
				preorder(root);
				printf("\n");
				break;
			case 'h':
				printf("Ʈ���� ���̴� %d\n", get_height(root));
				break;
			case 'c':
				printf("����� ������ %d\n", count(root));
				break;
			case 'm':
				key = get_maximum(root);
				if (key != NULL)
					printf("���� ū ���� %d\n", get_maximum(root));
				else
					printf("���� ��尡 �������� ����\n");
				break;
			case 'n':
				key = get_minimum(root);
				if (key != NULL)
					printf("���� ���� ���� %d\n", get_minimum(root));
				else
					printf("���� ��尡 �������� ����\n");
		}
		getchar();
		printf("Enter i<nsert>,d<elete>,s<earch>,p<rint>,h<eight>,c<ount>,m<ax>,n<min>,q<uit>:");
		scanf("%c", &c);
	}
}