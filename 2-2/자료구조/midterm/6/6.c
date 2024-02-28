#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
} TreeNode;

// key�� ���� Ž�� Ʈ�� root�� �����Ѵ�. 
// key�� �̹� root�ȿ� ������ ���Ե��� �ʴ´�.
TreeNode* insert_node(TreeNode* root, int key)  // �������� ����. ���� �����ð����� �ٷ��� ���� �κ��̴�.
{
	TreeNode* p, * t; // p�� �θ���, t�� ������ 
	TreeNode* n;	    // n�� ���ο� ���

	t = root;
	p = NULL;

	// Ž���� ���� ����, �ݺ��� �̿��ؼ� search(���� search�Լ� ����)
	while (t != NULL) { // �����尡 NULL�� �ɶ�����
		 //if( key == t->key ) return;
		p = t; // �����带 �θ���� �ϰ�
			// �����带 ����
		if (key < t->key)
			t = t->left;
		else
			t = t->right;
	}
	// key�� Ʈ�� �ȿ� �����Ƿ� ���� ����
	n = (TreeNode*)malloc(sizeof(TreeNode));
	// ������ ����
	n->key = key;
	n->left = n->right = NULL;

	// �θ� ���� ��ũ ����
	if (p != NULL)
		if (key < p->key)
			p->left = n;
		else
			p->right = n;
	else // ���ʿ� Ʈ���� ����־�����
		root = n;
	return root;
}
// ���� ��ȸ
void preorder(TreeNode* root) {
	if (root) {
		printf("%d ", root->key); 	// ��� �湮
		preorder(root->left);	// ���ʼ���Ʈ�� ��ȸ
		preorder(root->right);	// �����ʼ���Ʈ�� ��ȸ
	}
}
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);	// ���ʼ���Ʈ�� ��ȸ
		printf("%d ", root->key); 	// ��� �湮
		inorder(root->right);	// �����ʼ���Ʈ�� ��ȸ
	}
}
void printCheck(TreeNode* node)
{
	preorder(node); printf("\n");
	inorder(node); printf("\n");
}

TreeNode* copy_addChild(TreeNode* root)
{
	// �ڵ� �߰�
	TreeNode* new = (TreeNode*)malloc(sizeof(TreeNode));
	if (root != NULL) {
		if (root->left == NULL) {
			new->key = root->key;
			new->left = copy_addChild(root->right);
			new->right = copy_addChild(root->right);
		}
		else if (root->right == NULL) {
			new->key = root->key;
			new->left = copy_addChild(root->left);
			new->right = copy_addChild(root->left);
		}
		else if (root->left == NULL && root->right == NULL)
			new->key = root->key;
		else {
			new->key = root->key;
			new->left = copy_addChild(root->left);
			new->right = copy_addChild(root->right);
		}
	}
	else
		new = NULL;
	return new;
}

int main(void) // main�� �������� ����. 
{
	int key;

	TreeNode* root, * root2;

	// �Ʒ��� 6���� Ʈ���� ����� �κ����� �����ð��� �ٷ��� �ʾ����Ƿ� �Ű澲�� �ʾƵ� �ȴ�.
	root = NULL;
	scanf("%d", &key);
	while (key != -1) {
		root = insert_node(root, key);
		scanf("%d", &key);
	}

	root2 = copy_addChild(root);
	printCheck(root2);
}