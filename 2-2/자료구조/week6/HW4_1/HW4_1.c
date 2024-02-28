#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define TRUE 1
#define FALSE 0
#define MAX_TREE_SIZE 20

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;
//			root								root2
//			15									15
//		4		15							4		15
// 15		  16   25					15		  16  25
//														28
TreeNode n1 = { 15, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 15, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

TreeNode m1 = { 15, NULL, NULL };
TreeNode m2 = { 4, &n1, NULL };
TreeNode m3 = { 16, NULL, NULL };
TreeNode m7 = { 28, NULL, NULL }; // 추가
TreeNode m4 = { 25, NULL, &m7 }; // 변경
TreeNode m5 = { 15, &m3, &m4 };
TreeNode m6 = { 15, &m2, &m5 };
TreeNode* root2 = &m6;

//p281 Quiz 01
int get_nonleaf_count(TreeNode* t) { 
	int count = 0;

	if (t != NULL) {
		if (t->left != NULL || t->right != NULL)
			count++;
		count += get_nonleaf_count(t->left) + get_nonleaf_count(t->right);
	}
	return count;
	/*if (t == NULL)//종료조건
		return 0;
	else if (//t->left == NULL && t->right == NULL) {
		return 0;
	}
	else {
		return 1 + get_nonleaf_count(t->left) + get_nonleaf_count(t->right);
	}*/
}
//p281 Quiz 02
int equal(TreeNode* t1, TreeNode* t2) { 
	if (t1 == NULL && t2 == NULL)
		return TRUE;
	else if (t1 == NULL || t2 == NULL)
		return FALSE;
	/*else{
	*	if (t1->data != t2->data)
	*		return FALSE;
	*	else
	*		return equal(t1->left, t2->left) && equal(t1->right, t2->right);
	*/

	int ch = 0;
	if (t1->data == t2->data)
		return TRUE;
		
	ch = (equal(t1->left, t2->left) && equal(t1->right, t2->right));
	return ch;

}
//p308 #25
int get_oneleaf_count(TreeNode* node) { 
	int count = 0;

	if (node != NULL) {
		if (node->left != NULL && node->right == NULL)
			return 1;
		else if (node->left == NULL && node->right != NULL)
			return 1;
		else
			count = get_oneleaf_count(node->left) + get_oneleaf_count(node->right);
	}
	return count;
	/*
	if (t == NULL)//종료조건
		return 0;
	else if (//t->left == NULL && t->right == NULL) {
		return 0;
	}
	else if (t->left != NULL && t->right == NULL)//왼쪽만 있음//t->right ==NULL은 불필요한 조건
		return 1 + get_oneleaf(t->left);
	else if (t->left == NULL && t->right != NULL)//오른쪽만 있음//t->left ==NULL은 불필요한 조건
		return 1 + get_oneleaf(t->right);
	else {//두자식
		return get_nonleaf_count(t->left) + get_nonleaf_count(t->right);*/
}
//p308 #26
int get_twoleaf_count(TreeNode* node) { 
	int count = 0;

	if (node != NULL) {
		if (node->left != NULL && node->right != NULL)
			count++;
		count += get_twoleaf_count(node->left) + get_twoleaf_count(node->right);
	}
	return count;
	/*if (t == NULL)//종료조건
		return 0;
	else if (//t->left == NULL && t->right == NULL) {
		return 0;
	}
	else if (t->left != NULL && t->right == NULL)//왼쪽만 있음//t->right ==NULL은 불필요한 조건
		return get_oneleaf(t->left);
	else if (t->left == NULL && t->right != NULL)//오른쪽만 있음//t->left ==NULL은 불필요한 조건
		return get_oneleaf(t->right);
	else {//두자식
		return get_nonleaf_count(t->left) + get_nonleaf_count(t->right) + 1;
	*/
}
//p308 #27
int get_max(TreeNode* node) {
	int max = -1;

	if (node != NULL) {
		if (node->data > max)
			max = node->data;
		
		int l = get_max(node->left);
		if (l > max)
			max = l;
		int r = get_max(node->right);
		if (r > max)
			max = r;
	}
	return max;
	/*if (node != NULL)
		return max(max(node->left, node->right), node->data);
	else
		return INT_MIN;*/
}
int get_min(TreeNode* node) {
	int min = 100;

	if (node != NULL) {
		if (node->data < min)
			min = node->data;

		int l = get_min(node->left);
		if (l < min)
			min = l;
		int r = get_min(node->right);
		if (r < min)
			min = r;
	}
	return min;

	/*if (node != NULL)
		return min(min(node->left, node->right), node->data);
	else
		return INT_MAX;*/
}
//p308 #30
void node_increase(TreeNode* node) { 
	if (node != NULL) {
		node->data += 1;
		
		node_increase(node->left);
		node_increase(node->right);
	}
}
void preorder(TreeNode* root) // p271 코드 복사
{
	if (root != NULL) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
TreeNode* copy(TreeNode* node) {
	TreeNode *new = (TreeNode*)malloc(sizeof(TreeNode));
	
	if (node != NULL) {
		new->data = node->data;
		new->left = copy(node->left);
		new->right = copy(node->right);
	}
	else
		new= NULL;

	return new;

}
/*int search(TreeNode* root, int key, (TreeNode*)[] result) {
	int count = 0;

	if (root == NULL)
		return NULL;

	if (key == root->data) {
		result[count++] = root->data;
		return 1;
	}
	else {
		count = search(root->left, key, result) + search(root->right, key, result);
	}

	return count;
}*/
int main(void)
{
	TreeNode* result[MAX_TREE_SIZE];
	TreeNode* clone;
	int i, num;
	
	printf("가)\n");
	printf("트리 root 중 비단말노드의 개수는 %d.\n", get_nonleaf_count(root));
	printf("트리 root2 중 비단말노드의 개수는 %d.\n", get_nonleaf_count(root2));
	
	printf("트리 root 중 자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root));
	printf("트리 root2 중 자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root2));
	
	printf("트리 root 중 자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root));
	printf("트리 root2 중 자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root2));
	
	printf("트리 root 에서 가장 큰 수는 %d.\n", get_max(root));
	printf("트리 root2 에서 가장 큰 수는 %d.\n", get_max(root2));
	printf("트리 root 에서 가장 작은 수는 %d.\n", get_min(root));
	printf("트리 root2 에서 가장 작은 수는 %d.\n", get_min(root2));
	
	printf("\n 나)\n");
	/*num = search(root, 15, result);
	for (i = 0; i < num; i++)
		printf("(0x%p, %d), ", result[i], result[i]->data);
	printf("\n");*/
	
	printf("\n 다)\n");
	preorder(root);
	node_increase(root);
	printf("\n");
	preorder(root);
	printf("\n");
	printf("%s\n", equal(root, root) ? "같다" : "다르다");
	printf("%s\n", equal(root2, root2) ? "같다" : "다르다");
	printf("%s\n", equal(root, root2) ? "같다" : "다르다");
	
	printf("\n 라)\n");
	clone = copy(root);
	preorder(root);
	printf("\n");
	preorder(clone);
	printf("\n");
}